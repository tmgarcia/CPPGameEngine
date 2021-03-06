#include "Janitor.h"
#include "Renderer\GeneralGLWindow.h"
#include "Time\GameClock.h"
#include "Input\KeyInput.h"
#include "DebugTools\ConsolePrinter.h"
#include "SceneManager.h"

void Janitor::cleanupEngine()
{
	KeyInput::cleanup();
	GameClock::cleanup();
	GeneralGLWindow::cleanup();
	ConsolePrinter::cleanup();
	SceneManager::cleanup();
}