#pragma once
#include "Falcor.h"

using namespace Falcor;

class MyProject : public IRenderer {
private:
    GraphicsProgram::SharedPtr program = nullptr;
    GraphicsVars::SharedPtr programVars = nullptr;

    GraphicsState::SharedPtr graphicsState = nullptr;

    Scene::SharedPtr scene = nullptr;

public:
    void onLoad(RenderContext* pRenderContext) override;
    void onFrameRender(RenderContext* pRenderContext, const Fbo::SharedPtr& pTargetFbo) override;
    void onGuiRender(Gui* pGui) override;
};
