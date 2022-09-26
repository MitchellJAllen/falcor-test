import Scene.Raster;

VSOut vsMain(VSIn vIn) {
    return defaultVS(vIn);
}

float4 psMain(VSOut vsOut) : SV_TARGET {
    return float4(1, 0, 0, 1);
}
