#pragma once

#pragma region TEST_IMPLEMENTATION

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
char buffer[1024]; \
memset(buffer, 0, sizeof buffer); \
std::string output(__FUNCTION__); \
if (result == pExpected) { \
output += " passed in %lf ms (%lli cycle%s)\n"; \
snprintf(buffer, 1024, output.c_str(), elapsedTime, cycles, (cycles > 1 ? "s" : "")); \
OutputDebugStringA(buffer); \
} \
else { \
output += std::string(" (") + __FILE__ + " at line " + std::to_string(__LINE__) + \
") failed (expected " + pExpectedFormat + ")\n"; \
snprintf(buffer, 1024, output.c_str(), __VA_ARGS__); \
OutputDebugStringA(buffer); \
} \
memset(buffer, 0, sizeof buffer); \

#define TEST_OUT_VEC2 \
TEST_OUT("{%f %f} and got {%f %f}", \
pExpected.x, pExpected.y, \
result.x, result.y); \

#define TEST_OUT_VEC3 \
TEST_OUT("{%f %f %f} and got {%f %f %f}", \
pExpected.x, pExpected.y, pExpected.z, \
result.x, result.y, result.z); \

#define TEST_OUT_VEC4 \
TEST_OUT("{%f %f %f %f} and got {%f %f %f %f}", \
pExpected.x, pExpected.y, pExpected.z, pExpected.w, \
result.x, result.y, result.z, result.w); \

#define TEST_OUT_MAT4 \
float* r = result.mat16; \
float* e = pExpected.mat16; \
TEST_OUT("\n%f %f %f %f\n %f %f %f %f\n%f %f %f %f\n%f %f %f %f\n\nand got\n\n%f %f %f %f\n %f %f %f %f\n%f %f %f %f\n%f %f %f %f", \
e[0], e[1], e[2], e[3], e[4], e[5], e[6], e[7], e[8], e[9], e[10], e[11], e[12], e[13], e[14], e[15], \
r[0], r[1], r[2], r[3], r[4], r[5], r[6], r[7], r[8], r[9], r[10], r[11], r[12], r[13], r[14], r[15]); \

#define TEST_ERR(pCondition, pFormat, ...) \
char errBuffer[512]; \
memset(errBuffer, 0, sizeof errBuffer); \
std::string errOutput(__FUNCTION__); \
if (pCondition) { \
errOutput += std::string("ERROR from ") + __FILE__ + " at line " + \
std::to_string(__LINE__) + ": " + pFormat + "\n"; \
snprintf(errBuffer, 512, errOutput.c_str(), __VA_ARGS__); \
OutputDebugStringA(errBuffer); \
} \
else return;\
memset(errBuffer, 0, sizeof errBuffer); \

#pragma endregion

#pragma region Float2Test

void Float2CrossProductTest
(Float2 pA, Float2 pB, float pExpected) {
    TEST_START;
    float result = pA.CrossProduct(pB);
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float2DotProductTest
(Float2 pA, Float2 pB, float pExpected) {
    TEST_START;
    float result = pA.DotProduct(pB);
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float2PlanRotationTest
(Float2 pA, float pAngle, Float2 pExpected) {
    TEST_START;
    Float2 result = pA;
    result.PlanRotation(pAngle);
    TEST_STOP;
    TEST_OUT_VEC2;
}

void Float2MagnitudeTest(Float2 pA, float pExpected) {
    TEST_START;
    float result = pA.Magnitude();
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float2NormalizeTest
(Float2 pA, Float2 pExpected) {
    TEST_START;
    Float2 result = pA.GetNormalized();
    TEST_STOP;
    TEST_OUT_VEC2;
}

void Float2LerpTest
(Float2 pFrom, Float2 pTo, float pTime, Float2 pExpected) {
    TEST_START;
    Float2 result = Float2::Lerp(pFrom, pTo, pTime);
    TEST_STOP;
    TEST_OUT_VEC2;
}

void Float2AddTest
(Float2 pA, Float2 pB, Float2 pExpected) {
    TEST_START;
    Float2 result = pA + pB;
    TEST_STOP;
    TEST_OUT_VEC2;
}

void Float2SubTest
(Float2 pA, Float2 pB, Float2 pExpected) {
    TEST_START;
    Float2 result = pA - pB;
    TEST_STOP;
    TEST_OUT_VEC2;
}

void Float2MulSTest
(Float2 pA, float pB, Float2 pExpected) {
    TEST_START;
    Float2 result = pA * pB;
    TEST_STOP;
    TEST_OUT_VEC2;
}

void Float2DivSTest
(Float2 pA, float pB, Float2 pExpected) {
    TEST_ERR((pB == 0.f), "TEST FAILED (ZERO DIVIDER) !");
    TEST_START;
    Float2 result = pA / pB;
    TEST_STOP;
    TEST_OUT_VEC2;
}

#pragma endregion

#pragma region Float3Test

void Float3CrossProductTest
(Float3 pA, Float3 pB, Float3 pExpected) {
    TEST_START;
    Float3 result = pA.CrossProduct(pB);
    TEST_STOP;
    TEST_OUT_VEC3;
}

void Float3DotProductTest
(Float3 pA, Float3 pB, float pExpected) {
    TEST_START;
    float result = pA.DotProduct(pB);
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float3MagnitudeTest
(Float3 pA, float pExpected) {
    TEST_START;
    float result = pA.Magnitude();
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float3NormalizeTest
(Float3 pA, Float3 pExpected) {
    TEST_START;
    Float3 result = pA.GetNormalized();
    TEST_STOP;
    TEST_OUT_VEC3;
}

void Float3LerpTest
(Float3 pFrom, Float3 pTo, float pTime, Float3 pExpected) {
    TEST_START;
    Float3 result = Float3::Lerp(pFrom, pTo, pTime);
    TEST_STOP;
    TEST_OUT_VEC3;
}

void Float3AddTest
(Float3 pA, Float3 pB, Float3 pExpected) {
    TEST_START;
    Float3 result = pA + pB;
    TEST_STOP;
    TEST_OUT_VEC3;
}

void Float3SubTest
(Float3 pA, Float3 pB, Float3 pExpected) {
    TEST_START;
    Float3 result = pA - pB;
    TEST_STOP;
    TEST_OUT_VEC3;
}

void Float3MulSTest
(Float3 pA, float pB, Float3 pExpected) {
    TEST_START;
    Float3 result = pA * pB;
    TEST_STOP;
    TEST_OUT_VEC3;
}

void Float3DivSTest
(Float3 pA, float pB, Float3 pExpected) {
    TEST_ERR((pB == 0.f), "TEST FAILED (ZERO DIVIDER) !");
    TEST_START;
    Float3 result = pA / pB;
    TEST_STOP;
    TEST_OUT_VEC3;
}

#pragma endregion

#pragma region Float4Test

void Float4DotProductTest
(Float4 pA, Float4 pB, float pExpected) {
    TEST_START;
    float result = pA.DotProduct(pB);
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float4MagnitudeTest
(Float4 pA, float pExpected) {
    TEST_START;
    float result = pA.Magnitude();
    TEST_STOP;
    TEST_OUT("%f and got %f", pExpected, result);
}

void Float4NormalizeTest
(Float4 pA, Float4 pExpected) {
    TEST_START;
    Float4 result = pA.GetNormalized();
    TEST_STOP;
    TEST_OUT_VEC4;
}

void Float4AddTest
(Float4 pA, Float4 pB, Float4 pExpected) {
    TEST_START;
    Float4 result = pA + pB;
    TEST_STOP;
    TEST_OUT_VEC4;
}

void Float4SubTest
(Float4 pA, Float4 pB, Float4 pExpected) {
    TEST_START;
    Float4 result = pA - pB;
    TEST_STOP;
    TEST_OUT_VEC4;
}

void Float4MulSTest
(Float4 pA, float pB, Float4 pExpected) {
    TEST_START;
    Float4 result = pA * pB;
    TEST_STOP;
    TEST_OUT_VEC4;
}

void Float4DivSTest
(Float4 pA, float pB, Float4 pExpected) {
    TEST_ERR((pB == 0.f), "TEST FAILED (ZERO DIVIDER) !");
    TEST_START;
    Float4 result = pA / pB;
    TEST_STOP;
    TEST_OUT_VEC4;
}

#pragma endregion

#pragma region Mat4Test

void Mat4GetRotationXTest
(float pAngle, Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::GetRotationX(pAngle);
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4GetRotationYTest
(float pAngle, Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::GetRotationX(pAngle);
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4GetRotationZTest
(float pAngle, Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::GetRotationZ(pAngle);
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4GetRotationTest
(float pYaw, float pPitch, float pRoll, Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::GetRotation(pYaw, pPitch, pRoll);
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4GetTranslationTest
(Float3 pTranslation, Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::GetTranslation(pTranslation);
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4GetScaleTest
(Float3 pScale, Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::GetScale(pScale);
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4TransformTest
(Float3 pPosition, Float3 pRotation, Float3 pScale, Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::CreateTransformMatrix(pPosition, pRotation, pScale);
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4TransformQuatTest
(Float3 pPosition, Quaternion pRotation, Float3 pScale, Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::CreateTransformMatrix(pPosition, pRotation, pScale);
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4OrthographicTest
(float pRight, float pLeft, float pTop, float pBottom, float pFar, float pNear, Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::GetOrthographicMatrix(pRight, pLeft, pTop, pBottom, pFar, pNear);
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4PerspectiveTest
(float pAspect, float pFOV, float pFar, float pNear, Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::GetPerspectiveMatrix(pAspect, pFOV, pFar, pNear);
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4TransposeTest
(Mat4 pIn, Mat4 pExpected) {
    TEST_START;
    Mat4 result = pIn.GetTransposedMatrix();
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4InverseTest
(Mat4 pIn, Mat4 pExpected) {
    TEST_START;
    Mat4 result = pIn.GetInverseMatrix();;
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4IdentityTest
(Mat4 pExpected) {
    TEST_START;
    Mat4 result = Mat4::GetIdentityMatrix();;
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4MulTest
(Mat4 pIn, Mat4 pOther, Mat4 pExpected) {
    TEST_START;
    Mat4 result = pIn * pOther;
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4MulSTest
(Mat4 pIn, float pOther, Mat4 pExpected) {
    TEST_START;
    Mat4 result = pIn * pOther;
    TEST_STOP;
    TEST_OUT_MAT4;
}

void Mat4MulVTest
(Float4 pVec, Mat4 pIn, Float4 pExpected) {
    TEST_START;
    Float4 result = pVec * pIn;
    TEST_STOP;
    TEST_OUT_VEC4;
}

#pragma endregion
