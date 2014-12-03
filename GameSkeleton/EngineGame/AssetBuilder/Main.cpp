#include <Windows.h>
#include <QtOpenGL\qglwidget>
#include <Qt\qfileinfo.h>
#include <Qt\qdir.h>
#include <Qt\qimage.h>
#include <Qt\qdatetime.h>
#include <iostream>

const DWORD MAX_BUFFER_SIZE = 32767;
char objToBinDir[MAX_BUFFER_SIZE];
char workingAssetsDir[MAX_BUFFER_SIZE];
char outAssetsDir[MAX_BUFFER_SIZE];


void processShaderFiles()
{
	QString workingShaderDirPath = QString(workingAssetsDir) + "Shaders\\";
	QDir workingShaderDir (workingShaderDirPath);
	
	if(workingShaderDir.exists())
	{
		QStringList shaderFileFilters;
		shaderFileFilters << "*.glsl";

		workingShaderDir.setFilter(QDir::Files | QDir::NoSymLinks);
		workingShaderDir.setNameFilters(shaderFileFilters);
		QFileInfoList workingShaderFiles = workingShaderDir.entryInfoList();

		for(int i = 0; i < workingShaderFiles.size(); i++)
		{
			QFileInfo workingShader = workingShaderFiles.at(i);
			QFileInfo outShader(QString(outAssetsDir) + "Shaders\\" + workingShader.fileName());
			bool needsCopy = (!outShader.exists() || (outShader.lastModified() < workingShader.lastModified()));
			if(needsCopy)
			{
				QString copyCommand("echo f|xcopy /y \"" +  QDir::toNativeSeparators(workingShader.absoluteFilePath()) + "\" \"" + QDir::toNativeSeparators(outShader.absoluteFilePath()) + "\"");
				int result = system(copyCommand.toUtf8().constData());
			}
		}
	}
	else
	{
		qDebug("No working Shader folder.");
	}
}

void processImageFiles()
{
	QString workingImageDirPath = QString(workingAssetsDir) + "Textures\\";
	QDir workingImageDir (workingImageDirPath);
	if(workingImageDir.exists())
	{
		QStringList imageFileFilters;
		imageFileFilters << "*.png";

		workingImageDir.setFilter(QDir::Files | QDir::NoSymLinks);
		workingImageDir.setNameFilters(imageFileFilters);
		QFileInfoList workingImageFiles = workingImageDir.entryInfoList();

		for(int i = 0; i < workingImageFiles.size(); i++)
		{
			QFileInfo unprocessedImageFile = workingImageFiles.at(i);
			QFileInfo outImage(QString(outAssetsDir) + "Textures\\" + unprocessedImageFile.fileName());

			bool needsCopy = (!outImage.exists() || (outImage.lastModified() < unprocessedImageFile.lastModified()));
			if(needsCopy)
			{
				QDir::root().mkpath(outImage.absolutePath());
				QImage workingImage = QImage(QDir::toNativeSeparators(unprocessedImageFile.absoluteFilePath()));
				workingImage = QGLWidget::convertToGLFormat(workingImage);
				bool saved = workingImage.save(outImage.absoluteFilePath(), "PNG");
			}
		}
	}
	else
	{
		qDebug("No working Image folder.");
	}
}

void processModelFiles()
{
	QString workingModelDirPath = QString(workingAssetsDir) + "Models\\";
	QDir workingModelDir (workingModelDirPath);
	if(workingModelDir.exists())
	{
		QStringList modelFileFilters;
		modelFileFilters << "*.obj";

		workingModelDir.setFilter(QDir::Files | QDir::NoSymLinks);
		workingModelDir.setNameFilters(modelFileFilters);
		QFileInfoList workingModelFiles = workingModelDir.entryInfoList();
		for(int i = 0; i < workingModelFiles.size(); i++)
		{
			QFileInfo workingModelObj = workingModelFiles.at(i);
			QFileInfo workingModelBin (workingModelObj.path() + "\\" + workingModelObj.baseName() + ".bin");
			QFileInfo outModelBin (QString(outAssetsDir) + "Models\\" + workingModelBin.fileName());
			
			bool needsUpdate = (!workingModelBin.exists() || !outModelBin.exists() || (workingModelBin.lastModified() < workingModelObj.lastModified()));
			if(needsUpdate)
			{
				QString command("call \"" + QString(objToBinDir) + "ObjToBinaryWriter.exe\" ");
				command += "\"" + QDir::toNativeSeparators(workingModelObj.absoluteFilePath()) + "\" \"" + QDir::toNativeSeparators(workingModelBin.absoluteFilePath()) + "\"";
				int result = system(command.toLocal8Bit().constData());
				if(result != 0)
				{
					qDebug("ERROR CONVERTING MODEL OBJ, RESULT: " + result);
				}
				QString copyCommand("echo f|xcopy /y \"" + QDir::toNativeSeparators(workingModelBin.absoluteFilePath()) + "\" \"" + QString(outAssetsDir) + "Models\\" + workingModelBin.fileName() + "\"");
				int result2 = system(copyCommand.toLocal8Bit().constData());
			}

		}
	}
	else
	{
		qDebug("No working Model folder.");
	}
}

int main(int argc, char* argv[])
{
	qDebug("Begin Asset Building");
	GetEnvironmentVariable("ObjToBinDir",objToBinDir, MAX_BUFFER_SIZE);
	GetEnvironmentVariable("WorkingAssetsDir",workingAssetsDir, MAX_BUFFER_SIZE);
	GetEnvironmentVariable("OutAssetsDir",outAssetsDir, MAX_BUFFER_SIZE);

	processShaderFiles();
	processImageFiles();
	processModelFiles();
	qDebug("End Asset Building");
}