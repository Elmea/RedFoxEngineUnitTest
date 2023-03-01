#pragma once

#define TEST_START \
LARGE_INTEGER start,end,frequency; \
QueryPerformanceCounter(&start); \
QueryPerformanceFrequency(&frequency); \

#define TEST_STOP \
QueryPerformanceCounter(&end); \
long long cycles = end.QuadPart-start.QuadPart; \
double elapsedTime = (double)(cycles)/frequency.QuadPart; \
elapsedTime *= 1000.f; \

#define TEST_OUT(pExpectedFormat, ...) \
char buffer[256]; \
memset(buffer, 0, sizeof buffer); \
std::string output(__FUNCTION__); \
if (result == pExpected) { \
output += " passed in %lf ms (%lli cycle%s)\n"; \
snprintf(buffer, 256, output.c_str(), elapsedTime, cycles, (cycles > 1 ? "s" : "")); \
OutputDebugStringA(buffer); \
} \
else { \
output += std::string(" (") + __FILE__ + " at line " + std::to_string(__LINE__) + \
") failed (expected " + pExpectedFormat + ")\n"; \
snprintf(buffer, 256, output.c_str(), __VA_ARGS__); \
OutputDebugStringA(buffer); \
} \
memset(buffer, 0, sizeof buffer); \

#define TEST_ERR(pCondition, pFormat, ...) \
char errBuffer[256]; \
memset(errBuffer, 0, sizeof errBuffer); \
std::string errOutput(__FUNCTION__); \
if (pCondition) { \
errOutput += std::string("ERROR from ") + __FILE__ + " at line " + \
std::to_string(__LINE__) + ": " + pFormat + "\n"; \
snprintf(errBuffer, 256, errOutput.c_str(), __VA_ARGS__); \
OutputDebugStringA(errBuffer); \
} \
else return;\
memset(errBuffer, 0, sizeof errBuffer); \

#pragma region Float2Test

void Float2CrossProductTest
(const Float2& pA, const Float2& pB, const float& pExpected) {
    TEST_START;
    float result = pA.CrossProduct(pB);
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float2DotProductTest
(const Float2& pA, const Float2& pB, const float& pExpected) {
    TEST_START;
    float result = pA.DotProduct(pB);
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float2PlanRotationTest
(const Float2& pA, const float& pAngle, const Float2& pExpected) {
    TEST_START;
    Float2 result = pA;
    result.PlanRotation(pAngle);
    TEST_STOP;
    TEST_OUT("{%f %f} and got {%f %f}", 
             pExpected.x, pExpected.y,
             result.x, result.y);
}

void Float2MagnitudeTest(Float2& pA, const float& pExpected) {
    TEST_START;
    float result = pA.Magnitude();
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float2NormalizeTest
(Float2& pA, const Float2& pExpected) {
    TEST_START;
    Float2 result = pA.GetNormalized();
    TEST_STOP;
    TEST_OUT("{%f %f} and got {%f %f}",
             pExpected.x, pExpected.y,
             result.x, result.y);
}

void Float2LerpTest
(const Float2& pFrom, const Float2& pTo, const float& pTime, const Float2& pExpected) {
    TEST_START;
    Float2 result = Float2::Lerp(pFrom, pTo, pTime);
    TEST_STOP;
    TEST_OUT("{%f %f} and got {%f %f}",
             pExpected.x, pExpected.y,
             result.x, result.y);
}

void Float2AddTest
(const Float2& pA, const Float2& pB, const Float2& pExpected) {
    TEST_START;
    Float2 result = pA + pB;
    TEST_STOP;
    TEST_OUT("{%f %f} and got {%f %f}",
             pExpected.x, pExpected.y,
             result.x, result.y);
}

void Float2SubTest
(const Float2& pA, const Float2& pB, const Float2& pExpected) {
    TEST_START;
    Float2 result = pA - pB;
    TEST_STOP;
    TEST_OUT("{%f %f} and got {%f %f}",
             pExpected.x, pExpected.y,
             result.x, result.y);
}

void Float2MulSTest
(const Float2& pA, const float& pB, const Float2& pExpected) {
    TEST_START;
    Float2 result = pA * pB;
    TEST_STOP;
    TEST_OUT("{%f %f} and got {%f %f}",
             pExpected.x, pExpected.y,
             result.x, result.y);
}

void Float2DivSTest
(const Float2& pA, const float& pB, const Float2& pExpected) {
    TEST_ERR((pB == 0.f), "TEST FAILED (ZERO DIVIDER) !");
    TEST_START;
    Float2 result = pA / pB;
    TEST_STOP;
    TEST_OUT("{%f %f} and got {%f %f}",
             pExpected.x, pExpected.y,
             result.x, result.y);
}

#pragma endregion

#pragma region Float3Test

void Float3CrossProductTest
(const Float3& pA, const Float3& pB, const Float3& pExpected) {
    TEST_START;
    Float3 result = pA.CrossProduct(pB);
    TEST_STOP;
    TEST_OUT("{%f %f %f} and got {%f %f %f}", 
             pExpected.x, pExpected.y, pExpected.z,
             result.x, result.y, result.z);
}

void Float3DotProductTest
(const Float3& pA, const Float3& pB, const float& pExpected) {
    TEST_START;
    float result = pA.DotProduct(pB);
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float3MagnitudeTest
(Float3& pA, const float& pExpected) {
    TEST_START;
    float result = pA.Magnitude();
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float3NormalizeTest
(Float3& pA, const Float3& pExpected) {
    TEST_START;
    Float3 result = pA.GetNormalized();
    TEST_STOP;
    TEST_OUT("{%f %f %f} and got {%f %f %f}", 
             pExpected.x, pExpected.y, pExpected.z,
             result.x, result.y, result.z);
}

void Float3LerpTest
(const Float3& pFrom, const Float3& pTo, const float& pTime, const Float3& pExpected) {
    TEST_START;
    Float3 result = Float3::Lerp(pFrom, pTo, pTime);
    TEST_STOP;
    TEST_OUT("{%f %f %f} and got {%f %f %f}", 
             pExpected.x, pExpected.y, pExpected.z,
             result.x, result.y, result.z);
}

void Float3AddTest
(const Float3& pA, const Float3& pB, const Float3& pExpected) {
    TEST_START;
    Float3 result = pA + pB;
    TEST_STOP;
    TEST_OUT("{%f %f %f} and got {%f %f %f}", 
             pExpected.x, pExpected.y, pExpected.z,
             result.x, result.y, result.z);
}

void Float3SubTest
(const Float3& pA, const Float3& pB, const Float3& pExpected) {
    TEST_START;
    Float3 result = pA - pB;
    TEST_STOP;
    TEST_OUT("{%f %f %f} and got {%f %f %f}", 
             pExpected.x, pExpected.y, pExpected.z,
             result.x, result.y, result.z);
}

void Float3MulSTest
(const Float3& pA, const float& pB, const Float3& pExpected) {
    TEST_START;
    Float3 result = pA * pB;
    TEST_STOP;
    TEST_OUT("{%f %f %f} and got {%f %f %f}", 
             pExpected.x, pExpected.y, pExpected.z,
             result.x, result.y, result.z);
}

void Float3DivSTest
(const Float3& pA, const float& pB, const Float3& pExpected) {
    TEST_ERR((pB == 0.f), "TEST FAILED (ZERO DIVIDER) !");
    TEST_START;
    Float3 result = pA / pB;
    TEST_STOP;
    TEST_OUT("{%f %f %f} and got {%f %f %f}", 
             pExpected.x, pExpected.y, pExpected.z,
             result.x, result.y, result.z);
}

#pragma endregion

#pragma region Float4Test

void Float4DotProductTest
(const Float4& pA, const Float4& pB, const float& pExpected) {
    TEST_START;
    float result = pA.DotProduct(pB);
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float4MagnitudeTest
(Float4& pA, const float& pExpected) {
    TEST_START;
    float result = pA.Magnitude();
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float4NormalizeTest
(Float4& pA, const Float4& pExpected) {
    TEST_START;
    Float4 result = pA.GetNormalized();
    TEST_STOP;
    TEST_OUT("{%f %f %f %f} and got {%f %f %f %f}",
             pExpected.x, pExpected.y, pExpected.z, pExpected.w,
             result.x, result.y, result.z, result.w);
}

void Float4AddTest
(const Float4& pA, const Float4& pB, const Float4& pExpected) {
    TEST_START;
    Float4 result = pA + pB;
    TEST_STOP;
    TEST_OUT("{%f %f %f %f} and got {%f %f %f %f}",
             pExpected.x, pExpected.y, pExpected.z, pExpected.w,
             result.x, result.y, result.z, result.w);
}

void Float4SubTest
(const Float4& pA, const Float4& pB, const Float4& pExpected) {
    TEST_START;
    Float4 result = pA - pB;
    TEST_STOP;
    TEST_OUT("{%f %f %f %f} and got {%f %f %f %f}",
             pExpected.x, pExpected.y, pExpected.z, pExpected.w,
             result.x, result.y, result.z, result.w);
}

void Float4MulSTest
(const Float4& pA, const float& pB, const Float4& pExpected) {
    TEST_START;
    Float4 result = pA * pB;
    TEST_STOP;
    TEST_OUT("{%f %f %f %f} and got {%f %f %f %f}",
             pExpected.x, pExpected.y, pExpected.z, pExpected.w,
             result.x, result.y, result.z, result.w);
}

void Float4DivSTest
(const Float4& pA, const float pB, const Float4& pExpected) {
    TEST_ERR((pB == 0.f), "TEST FAILED (ZERO DIVIDER) !");
    TEST_START;
    Float4 result = pA / pB;
    TEST_STOP;
    TEST_OUT("{%f %f %f %f} and got {%f, %f, %f, %f}",
             pExpected.x, pExpected.y, pExpected.z, pExpected.w,
             result.x, result.y, result.z, result.w);
}

#pragma endregion


#pragma region Mat4

void Mat4GetRotationXTest
(const float& pAngle, const Mat4& pExpected) {
    TEST_START;
    Mat4 result = Mat4::GetRotationX(pAngle);
    TEST_STOP;
    
    const float* r = result.mat16;
    const float* e = pExpected.mat16;
    TEST_OUT("%f %f %f %f\n%f %f %f %f %f\n%f %f %f %f\n%f %f %f %f\n\nand got\n\n%f %f %f %f\n%f %f %f %f %f\n%f %f %f %f\n%f %f %f %f\n\n",
             r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9], r[10], r[11], r[12], r[13], r[14], r[15],
             e[0], e[1], e[2], e[3], e[4], e[5], e[6], e[7], e[8], e[9], e[10], e[11], e[12], e[13], e[14], e[15]);
}

#pragma endregion
