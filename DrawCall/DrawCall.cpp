#include "DrawCall.h"

FALCOR_EXPORT_D3D12_AGILITY_SDK

void MyProject::onLoad(RenderContext* pRenderContext) {
    // VAO

    this->vao = Vao::create(Vao::Topology::TriangleList);

    // Rasterizer State

    RasterizerState::Desc rasterizerStateDesc{};
    rasterizerStateDesc.setCullMode(RasterizerState::CullMode::None);

    this->rasterizerState = RasterizerState::create(rasterizerStateDesc);

    // Graphics Program

    Program::Desc programDesc{};
    programDesc.addShaderLibrary("Samples/DrawCall/DrawCall.3d.slang");
    programDesc.entryPoint(ShaderType::Vertex, "vertexMain");
    programDesc.entryPoint(ShaderType::Pixel, "pixelMain");

    this->graphicsProgram = GraphicsProgram::create(programDesc);

    // Graphics State

    this->graphicsState = GraphicsState::create();
    this->graphicsState->setVao(this->vao);
    this->graphicsState->setRasterizerState(this->rasterizerState);
    this->graphicsState->setProgram(this->graphicsProgram);

    // Graphics Vars

    this->graphicsVars = GraphicsVars::create(this->graphicsProgram->getReflector());
}

void MyProject::onFrameRender(RenderContext* pRenderContext, const Fbo::SharedPtr& pTargetFbo) {
    const float4 clearColor{ 0.f, 0.f, 0.5f, 1.f };

    pRenderContext->clearFbo(pTargetFbo.get(), clearColor, 1.f, 0);

    this->graphicsState->setFbo(pTargetFbo);

    pRenderContext->draw(this->graphicsState.get(), this->graphicsVars.get(), 3, 0);
}

int main() {
    MyProject::UniquePtr pRenderer{ std::make_unique<MyProject>() };

    SampleConfig config{};
    config.windowDesc.width = 1280;
    config.windowDesc.height = 720;
    config.windowDesc.title = "Test";
    config.windowDesc.resizableWindow = false;

    Sample::run(config, pRenderer);

    return 0;
}

