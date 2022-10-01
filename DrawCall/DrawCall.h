#pragma once
#include "Falcor.h"

using namespace Falcor;

class MyProject : public IRenderer {
private:
    GraphicsState::SharedPtr graphicsState = nullptr;
    GraphicsVars::SharedPtr graphicsVars = nullptr;

    Vao::SharedPtr vao = nullptr;
    RasterizerState::SharedPtr rasterizerState = nullptr;
    GraphicsProgram::SharedPtr graphicsProgram = nullptr;

public:
    void onLoad(RenderContext* pRenderContext) override;
    void onFrameRender(RenderContext* pRenderContext, const Fbo::SharedPtr& pTargetFbo) override;
};
