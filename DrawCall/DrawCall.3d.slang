struct VertexOutput {
    float4 position : SV_POSITION;
    float3 color : COLOR;
}

VertexOutput vertexMain(uint vertexId: SV_VertexID) {
    VertexOutput output;

    static float3 vertexPositions[3] = {
        float3(0, 0.5, 0),
        float3(-0.5, -0.5, 0),
        float3(0.5, -0.5, 0)
    };

    static float3 vertexColors[3] = {
        float3(1, 0, 0),
        float3(0, 1, 0),
        float3(0, 0, 1)
    };

    output.position = float4(vertexPositions[vertexId], 1);
    output.color = vertexColors[vertexId];

    return output;
}

float4 pixelMain(VertexOutput vertexOutput) : SV_TARGET {
    return float4(vertexOutput.color, 1);
}
