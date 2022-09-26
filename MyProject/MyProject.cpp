#include "MyProject.h"

FALCOR_EXPORT_D3D12_AGILITY_SDK

void MyProject::onLoad(RenderContext* pRenderContext) {
    Camera::SharedPtr camera{ Camera::create() };
    camera->setPosition(float3{ 0.f, 3.f, 3.f });
    camera->setTarget(float3{ 0.f, 0.f, 0.f });

    TriangleMesh::SharedPtr quad{ TriangleMesh::createQuad() };

    StandardMaterial::SharedPtr material{ StandardMaterial::create()};

    SceneBuilder::Node node{};
    node.transform = rmcv::identity<rmcv::mat4>();

    SceneBuilder::SharedPtr sceneBuilder{ SceneBuilder::create() };

    CameraID cameraId{ sceneBuilder->addCamera(camera) };
    MeshID meshId{ sceneBuilder->addTriangleMesh(quad, material) };
    NodeID nodeId{ sceneBuilder->addNode(node) };

    sceneBuilder->addMeshInstance(nodeId, meshId);

    this->scene = sceneBuilder->getScene();

    Program::Desc programDesc{};
    programDesc.addShaderModules(this->scene->getShaderModules());
    programDesc.addTypeConformances(this->scene->getTypeConformances());
    programDesc.addShaderLibrary("Samples/MyProject/MyProject.3d.slang").vsEntry("vsMain").psEntry("psMain");

    this->program = GraphicsProgram::create(programDesc, this->scene->getSceneDefines());
    this->programVars = GraphicsVars::create(this->program->getReflector());

    this->graphicsState = GraphicsState::create();
    this->graphicsState->setProgram(this->program);
}

void MyProject::onFrameRender(RenderContext* pRenderContext, const Fbo::SharedPtr& pTargetFbo) {
    const float4 clearColor{ 0.f, 0.f, 0.5f, 1.f };

    pRenderContext->clearFbo(pTargetFbo.get(), clearColor, 1.f, 0);

    this->graphicsState->setFbo(pTargetFbo);
    this->scene->rasterize(pRenderContext, this->graphicsState.get(), this->programVars.get(), RasterizerState::CullMode::None);
}

void MyProject::onGuiRender(Gui* pGui) {
    Gui::Window window{ pGui, "Scene", { 400, 300 }, { 0, 100 } };

    this->scene->renderUI(window);
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
