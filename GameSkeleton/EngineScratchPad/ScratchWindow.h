#pragma once

#include <Qt\qapplication.h>
#include <Qt\qboxlayout.h>
#include <Qt\qmainwindow.h>
#include "GeneralGLWindow.h"
#include "DebugMenu\DebugMenu.h"
#include "MathTools\TransformationMatrixMaker.h";
#include "MathTools\Random.h";

#include <iostream>

using std::cout;
using std::endl;

const GLuint WINDOW_WIDTH = 1500;
const GLuint WINDOW_HEIGHT = 900;

class ScratchWindow : public QMainWindow
{
	Q_OBJECT

	QTimer updateTimer;

public:
	ScratchWindow()
	{
		this->show();
		cout << "constructing scratch window" << endl;
		
		connect(&updateTimer, SIGNAL(timeout()), this, SLOT(update()));
		updateTimer.setInterval(1);
		updateTimer.start(0);

		//DebugMenu* dMenu = new DebugMenu();
		//mainLayout->addWidget(dMenu);

		GeneralGLWindow::getInstance();
		GeneralGLWindow::getInstance().setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		setCentralWidget(&GeneralGLWindow::getInstance());
		GeneralGLWindow::getInstance().show();

		GeneralGLWindow::getInstance();

		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(keyPressed(QKeyEvent*)), this, SLOT(keyPressReaction(QKeyEvent*)));
		QObject::connect(&GeneralGLWindow::getInstance(), SIGNAL(mouseMoved(QMouseEvent*)), this, SLOT(mouseMoveReaction(QMouseEvent*)));

		//dMenu->addFloatSlider(&val, 0, 10, "Label");

		setup();

		this->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
		this->move(300, 0);
	}
	~ScratchWindow()
	{

	}
protected:
	TextureInfo* eyeTexture;
	GeometryInfo* plane;
	ShaderInfo* alphaTextureShader;

	AlphaMapInfo* discAlpha;
	AlphaMapInfo* textAAlpha;
	AlphaMapInfo* textBAlpha;
	AlphaMapInfo* eyeAlpha1;
	AlphaMapInfo* eyeAlpha2;
	AlphaMapInfo* eyeAlpha3;
	AlphaMapInfo* eyeAlpha4;
	AlphaMapInfo* eyeAlpha5;
	AlphaMapInfo* eyeAlpha6;

	float val;
	void setup();
	Camera camera;
	void loadLevel();
	void keyPressEvent(QKeyEvent *event);
	void updateShaderInfo();
	void setupEyes();

	struct Eye
	{
		int blinkStage;
		int blinkFrame;
		float scale;
		bool isBlinking;
		bool isClosing;
		vec3 position;
		mat4 modelToWorld;
		mat4 fullTransform;
		RenderableInfo* renderable;
		Eye(vec3 pos, float _scale, int _blinkFrame)
		{
			position = pos;
			scale = _scale;
			blinkFrame = _blinkFrame;
			isBlinking = false;
			isClosing = false;
		}
		void setupRenderable(GeometryInfo* plane, ShaderInfo* alphaTextureShader, TextureInfo* eyeTexture, AlphaMapInfo* eyeAlpha1)
		{
			renderable = GeneralGLWindow::getInstance().addRenderable(plane, modelToWorld, alphaTextureShader, true, PRIORITY_1, true, eyeTexture, eyeAlpha1);
			GeneralGLWindow::getInstance().addRenderableUniformParameter(renderable, "fullTransformMatrix", PT_MAT4, &fullTransform[0][0]);
		}
		void checkBlinkFrame(int frame)
		{
			if(frame%blinkFrame==0 && !isBlinking)
			{
				startBlink();
			}
		}
		void updateTransforms(vec3 cameraPosition, vec3 cameraUp, mat4 worldToProjection)
		{
			mat4 billboardTransform = TransformationMatrixMaker::getInstance().getBillboardTransformation(position, cameraPosition, cameraUp, true);
			modelToWorld = billboardTransform * glm::rotate(90.0f, vec3(1,0,0)) * glm::scale(vec3(scale, 1, scale));
			fullTransform = worldToProjection * modelToWorld;
		}
		void startBlink()
		{
			isBlinking = true;
			isClosing = true;
			blinkStage = 0;
		}
		void stopBlinking()
		{
			isBlinking = false;
			isClosing = false;
			blinkStage = 0;
		}
		void updateBlinkStage(AlphaMapInfo* nextAlpha)
		{
			if(blinkStage < 0)
			{
				stopBlinking();
				blinkStage = 0;
			}
			else
			{
				if(blinkStage!=6)
				{
					blink(nextAlpha);
				}
				else
				{
					isClosing = false;
				}
				if(isClosing)
				{
					blinkStage++;
				}
				else
				{
					blinkStage--;
				}
			}
		}
		void blink(AlphaMapInfo* nextAlpha)
		{
			renderable->alphaMap = nextAlpha;
		}
	};
	QList<Eye*> eyes;
	int numEyes;
private slots:
	void update();

public slots:
	void keyPressReaction(QKeyEvent* e);
	void mouseMoveReaction(QMouseEvent* e);
};

