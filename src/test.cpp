#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <string.h>

// TODO(vegasword): Some tests need to be implemented with hand written expected result
// NOTE(vegasword): I've done only the test compared to cglm functions
// TODO(vegasword): Iterations (for loop for each test to stress test)
// TODO(vegasword): Randomized tests

#include <cglm/cglm.h>
#include <cglm/struct/vec2.h>
#include <cglm/struct/vec3.h>
#include <cglm/struct/mat4.h>
#include <cglm/struct/quat.h>
#include <cglm/affine.h>
#include <cglm/types-struct.h>


#define REDFOXMATHS_IMPLEMENTATION
#include <RedFoxMaths.hpp>
using namespace RedFoxMaths;

#include <test.hpp>

int main() 
{
#pragma region Float2Test
    TEST_SEQ_START("VECTOR 2");
    {
        float expected = glm_vec2_cross(new(vec2){2.f,3.f}, new(vec2){7.f,8.f});
        Float2CrossProductTest({2.f,3.f}, {7.f,8.f}, expected);
    }
    {
        float expected = glm_vec2_dot(new(vec2){2.f,3.f}, new(vec2){7.f,8.f});
        Float2DotProductTest({2.f,3.f}, {7.f,8.f}, expected);
    }
    {
        vec2s rotated;
        glm_vec2_rotate(new(vec2){2.f,3.f}, PI/2.f, rotated.raw);
        Float2PlanRotationTest({2.f,3.f}, 90.f, {rotated.x,rotated.y});
    }
    {
        float expected = glm_vec2_norm(new(vec2){2.f,3.f});
        Float2 in({2.f,3.f});
        Float2MagnitudeTest(in, expected);
    }
    {
        vec2s expected = {2.f,3.f};
        glm_vec2_normalize(expected.raw);
        Float2 in({2.f,3.f});
        Float2NormalizeTest(in, {expected.x,expected.y});
    }
    {
        vec2s expected = {0};
        glm_vec2_lerp(new(vec2){2.f,3.f}, new(vec2){4.f,5.f}, 0.5f, expected.raw);
        Float2LerpTest({2.f,3.f}, {4.f,5.f}, 0.5f, {expected.x,expected.y});
    }
    {
        vec2s expected = {0};
        glm_vec2_add(new(vec2){2.f,3.f}, new(vec2){4.f,5.f}, expected.raw);
        Float2AddTest({2.f,3.f}, {4.f,5.f}, {expected.x,expected.y});
    }
    {
        vec2s expected = {0};
        glm_vec2_sub(new(vec2){2.f,3.f}, new(vec2){4.f,5.f}, expected.raw);
        Float2SubTest({2.f,3.f}, {4.f,5.f}, {expected.x,expected.y});
    }
    {
        vec2s expected = {0};
        glm_vec2_scale(new(vec2){2.f,3.f}, 4.f, expected.raw);
        Float2MulSTest({2.f,3.f}, 4.f, {expected.x,expected.y});
    }
    {
        vec2s expected = {0};
        glm_vec2_divs(new(vec2){2.f,3.f}, 4.f, expected.raw);
        Float2DivSTest({2.f,3.f}, 4.f, {expected.x,expected.y});
    }
    TEST_SEQ_END();
#pragma endregion
    
#pragma region Float3Test
    //NOT TESTED YET: GetSphericalCoords
    TEST_SEQ_START("VECTOR 3");
    {
        vec3s expected = {0};
        glm_vec3_cross(new(vec3){2.f,3.f,4.f}, new(vec3){7.f,8.f,9.f}, expected.raw);
        Float3CrossProductTest({2.f,3.f,4.f}, {7.f,8.f,9.f}, {expected.x,expected.y,expected.z});
    }
    {
        float expected = glm_vec3_dot(new(vec3){2.f,3.f,4.f}, new(vec3){7.f,8.f,9.f});
        Float3DotProductTest({2.f,3.f,4.f}, {7.f,8.f,9.f}, expected);
    }
    {
        float expected = glm_vec3_norm(new(vec3){2.f,3.f,4.f});
        Float3 in({2.f,3.f,4.f});
        Float3MagnitudeTest(in, expected);
    }
    {
        vec3s expected = {2.f,3.f,4.f};
        glm_vec3_normalize(expected.raw);
        Float3 in({2.f,3.f,4.f});
        Float3NormalizeTest(in, {expected.x,expected.y,expected.z});
    }
    {
        vec3s expected = {0};
        glm_vec3_lerp(new(vec3){2.f,3.f,4.f}, new(vec3){4.f,5.f,6.f}, 0.5f, expected.raw);
        Float3LerpTest({2.f,3.f,4.f}, {4.f,5.f,6.f}, 0.5f, {expected.x,expected.y,expected.z});
    }
    {
        vec3s expected = {0};
        glm_vec3_add(new(vec3){2.f,3.f,4.f}, new(vec3){4.f,5.f,6.f}, expected.raw);
        Float3AddTest({2.f,3.f,4.f}, {4.f,5.f,6.f}, {expected.x,expected.y,expected.z});
    }
    {
        vec3s expected = {0};
        glm_vec3_sub(new(vec3){2.f,3.f,4.f}, new(vec3){4.f,5.f,6.f}, expected.raw);
        Float3SubTest({2.f,3.f,4.f}, {4.f,5.f,6.f}, {expected.x,expected.y,expected.z});
    }
    {
        vec3s expected = {0};
        glm_vec3_scale(new(vec3){2.f,3.f,4.f}, 4.f, expected.raw);
        Float3MulSTest({2.f,3.f,4.f}, 4.f, {expected.x,expected.y,expected.z});
    }
    {
        vec3s expected = {0};
        glm_vec3_divs(new(vec3){2.f,3.f,4.f}, 4.f, expected.raw);
        Float3DivSTest({2.f,3.f,4.f}, 4.f, {expected.x,expected.y,expected.z});
    }
    TEST_SEQ_END();
#pragma endregion
    
#pragma region Float4Test
    //NOT TESTED YET: Homogenize
    TEST_SEQ_START("VECTOR 4");
    {
        float expected = glm_vec4_dot(new(vec4){2.f,3.f,4.f,5.f}, new(vec4){7.f,8.f,9.f,10.f});
        Float4DotProductTest({2.f,3.f,4.f,5.f}, {7.f,8.f,9.f,10.f}, expected);
    }
    {
        float expected = glm_vec4_norm(new(vec4){2.f,3.f,4.f,5.f});
        Float4 in({2.f,3.f,4.f,5.f});
        Float4MagnitudeTest(in, expected);
    }
    {
        vec4s expected = {2.f,3.f,4.f,5.f};
        glm_vec4_normalize(expected.raw);
        Float4 in({2.f,3.f,4.f,5.f});
        Float4NormalizeTest(in, {expected.x,expected.y,expected.z,expected.w});
    }
    {
        vec4s expected = {0};
        glm_vec4_add(new(vec4){2.f,3.f,4.f,5.f}, new(vec4){4.f,5.f,6.f,7.f}, expected.raw);
        Float4AddTest({2.f,3.f,4.f,5.f}, {4.f,5.f,6.f,7.f}, {expected.x,expected.y,expected.z,expected.w});
    }
    {
        vec4s expected = {0};
        glm_vec4_sub(new(vec4){2.f,3.f,4.f,5.f}, new(vec4){4.f,5.f,6.f,7.f}, expected.raw);
        Float4SubTest({2.f,3.f,4.f,5.f}, {4.f,5.f,6.f,7.f}, {expected.x,expected.y,expected.z,expected.w});
    }
    {
        vec4s expected = {0};
        glm_vec4_scale(new(vec4){2.f,3.f,4.f,5.f}, 4.f, expected.raw);
        Float4MulSTest({2.f,3.f,4.f,5.f}, 4.f, {expected.x,expected.y,expected.z,expected.w});
    }
    {
        vec4s expected = {0};
        glm_vec4_divs(new(vec4){2.f,3.f,4.f,5.f}, 4.f, expected.raw);
        Float4DivSTest({2.f,3.f,4.f,5.f}, 4.f, {expected.x,expected.y,expected.z,expected.w});
    }
    TEST_SEQ_END();
#pragma endregion
    
#pragma region Mat4
    //NOT TESTED YET:
    //    GetComplementaryMatrix
    //    GetCoMatrix
    TEST_SEQ_START("MATRIX 4");
    {
        mat4 id, ex;
        glm_mat4_identity(id);
        glm_rotate_x(id, PI/2, ex);
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4GetRotationXTest(PI/2, expected);
    }
    {
        mat4 id, ex;
        glm_mat4_identity(id);
        glm_rotate_y(id, PI/2, ex);
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4GetRotationYTest(PI/2, expected);
    }
    {
        mat4 id, ex;
        glm_mat4_identity(id);
        glm_rotate_z(id, PI/2, ex);
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4GetRotationZTest(PI/2, expected);
    }
    {
        mat4 id;
        glm_mat4_identity(id);
        glm_rotate(id, PI/2, new(vec3){1.f, 1.f, 1.f});
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)id;
        Mat4GetRotationTest(PI/2, PI/2, PI/2, expected);
    }
    {
        mat4 ex;
        glm_mat4_identity(ex);
        glm_translate(ex, new(vec3){2.f,3.f,4.f});
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4GetTranslationTest({2.f,3.f,4.f}, expected);
    }
    {
        mat4 ex;
        glm_mat4_identity(ex);
        glm_scale(ex, new(vec3){2.f,3.f,4.f});
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4GetScaleTest({2.f,3.f,4.f}, expected);
    }
    {
        mat4 ex;
        glm_mat4_identity(ex);
        glm_translate(ex, new(vec3){2.f,3.f,4.f});
        glm_rotate(ex, PI/2, new(vec3){1.f, 1.f, 1.f});
        glm_scale(ex, new(vec3){1.f,1.f,1.f});
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4TransformTest({2.f,3.f,4.f},{PI/2,PI/2,PI/2},{1.f,1.f,1.f}, expected);
    }
    {
        mat4 ex; versor q;
        glm_mat4_identity(ex);
        glm_translate(ex, new(vec3){2.f,3.f,4.f});
        glm_quat_identity(q);
        glm_quat_rotate(ex, q, ex);
        glm_scale(ex, new(vec3){1.f,1.f,1.f});
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4TransformQuatTest({2.f,3.f,4.f},{1.f,0.f,0.f,0.f},{1.f,1.f,1.f}, expected);
    }
    {
        mat4 ex;
        glm_mat4_identity(ex);
        glm_ortho(1.f,2.f,3.f,4.f,5.f,6.f,ex);
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4OrthographicTest(2.f,1.f,4.f,3.f,6.f,5.f,expected);
    }
    {
        mat4 ex;
        glm_mat4_identity(ex);
        glm_perspective(90.f,1.f,0.1f,100.f,ex);
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4PerspectiveTest(1.f,90.f,100.f,0.1f,expected);
    }
    {
        vec4 l0 = {1.f,2.f,3.f,4.f};
        vec4 l1 = {5.f,6.f,7.f,8.f};
        vec4 l2 = {9.f,10.f,11.f,12.f};
        vec4 l3 = {13.f,14.f,15.f,16.f};
        
        mat4 m1, ex;
        glm_vec4_copy(l0, m1[0]);
        glm_vec4_copy(l1, m1[1]);
        glm_vec4_copy(l2, m1[2]);
        glm_vec4_copy(l3, m1[3]);
        glm_mat4_copy(m1, ex);
        glm_mat4_transpose(ex);
        
        Mat4 mat1, expected;
        float* mat1Ptr = mat1.mat16;
        mat1Ptr = (float*)m1;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4TransposeTest(mat1, expected);
    }
    {
        vec4 l0 = {1.f,2.f,3.f,4.f};
        vec4 l1 = {5.f,6.f,7.f,8.f};
        vec4 l2 = {9.f,10.f,11.f,12.f};
        vec4 l3 = {13.f,14.f,15.f,16.f};
        
        mat4 m1, ex;
        glm_vec4_copy(l0, m1[0]);
        glm_vec4_copy(l1, m1[1]);
        glm_vec4_copy(l2, m1[2]);
        glm_vec4_copy(l3, m1[3]);
        glm_mat4_inv_fast(m1, ex);
        
        Mat4 mat1, expected;
        float* mat1Ptr = mat1.mat16;
        mat1Ptr = (float*)m1;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4InverseTest(mat1, expected);
    }
    {
        mat4 ex;
        glm_mat4_identity(ex);
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4IdentityTest(expected);
    }
    {
        vec4 l0 = {1.f,2.f,3.f,4.f};
        vec4 l1 = {5.f,6.f,7.f,8.f};
        vec4 l2 = {9.f,10.f,11.f,12.f};
        vec4 l3 = {13.f,14.f,15.f,16.f};
        
        mat4 ex, m1, m2;
        glm_vec4_copy(l0, m1[0]);
        glm_vec4_copy(l1, m1[1]);
        glm_vec4_copy(l2, m1[2]);
        glm_vec4_copy(l3, m1[3]);
        glm_vec4_copy(l3, m2[0]);
        glm_vec4_copy(l2, m2[1]);
        glm_vec4_copy(l1, m2[2]);
        glm_vec4_copy(l0, m2[3]);
        glm_mat4_mul(m1, m2, ex);
        
        Mat4 mat1, mat2, expected;
        float* mat1Ptr = mat1.mat16;
        mat1Ptr = (float*)m1;
        float* mat2Ptr = mat2.mat16;
        mat2Ptr = (float*)m2;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4MulTest(mat1, mat2, expected);
    }
    {
        float s = 5.f;
        vec4 l0 = {1.f,2.f,3.f,4.f};
        vec4 l1 = {5.f,6.f,7.f,8.f};
        vec4 l2 = {9.f,10.f,11.f,12.f};
        vec4 l3 = {13.f,14.f,15.f,16.f};
        
        mat4 ex, m1;
        glm_vec4_copy(l0, m1[0]);
        glm_vec4_copy(l1, m1[1]);
        glm_vec4_copy(l2, m1[2]);
        glm_vec4_copy(l3, m1[3]);
        glm_mat4_copy(m1, ex);
        glm_mat4_scale(ex, s);
        
        Mat4 mat1, expected;
        float* mat1Ptr = mat1.mat16;
        mat1Ptr = (float*)m1;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)ex;
        Mat4MulSTest(mat1, s, expected);
    }
    {
        vec4 s = {111.f, 222.f, 333.f, 444.f};
        vec4 l0 = {1.f,2.f,3.f,4.f};
        vec4 l1 = {5.f,6.f,7.f,8.f};
        vec4 l2 = {9.f,10.f,11.f,12.f};
        vec4 l3 = {13.f,14.f,15.f,16.f};
        
        mat4 m1; vec4 ex;
        glm_vec4_copy(l0, m1[0]);
        glm_vec4_copy(l1, m1[1]);
        glm_vec4_copy(l2, m1[2]);
        glm_vec4_copy(l3, m1[3]);
        glm_mat4_mulv(m1, s, ex);
        
        Float4 scale({111.f, 222.f, 333.f, 444.f});
        Mat4 mat1;
        float* mat1Ptr = mat1.mat16;
        mat1Ptr = (float*)m1;
        Float4 expected;
        expected.x = ex[0];
        expected.y = ex[1];
        expected.z = ex[2];
        expected.w = ex[3];
        
        Mat4MulVTest(scale, mat1, expected);
    }
    TEST_SEQ_END();
#pragma endregion
    
#pragma QuatTest
    TEST_SEQ_START("QUATERNION");
    {
        versors q = glms_quat_init(1.f,2.f,3.f,4.f);
        q = glms_quat_normalize(q);
        QuatNormalizeTest({4.f,1.f,2.f,3.f}, {q.w,q.x,q.y,q.z});
    }
    {
        versors q = glms_quat_init(1.f,2.f,3.f,4.f);
        float expected = glms_quat_dot(q,q);
        QuatModulusTest({4.f,1.f,2.f,3.f}, expected);
    }
    {
        versors q = glms_quat_init(1.f,2.f,3.f,4.f);
        float expected = sqrtf(glms_quat_dot(q,q));
        QuatSqrModulusTest({4.f,1.f,2.f,3.f}, expected);
    }
    {
        versors q = glms_quat_init(1.f,2.f,3.f,4.f);
        mat4s mat = glms_quat_mat4(q);
        
        Mat4 expected;
        float* expectedPtr = expected.mat16;
        expectedPtr = (float*)mat.raw;
        QuatToMatTest({4.f,1.f,2.f,3.f}, expected);
    }
    {
        versors p = glms_quat_init(1.f,2.f,3.f,4.f);
        versors q = glms_quat_init(5.f,6.f,7.f,8.f);
        versors e = glms_quat_mul(p, q);
        Quaternion expected(e.x,e.y,e.z,e.w);
        QuatHamiltonTest({4.f,1.f,2.f,3.f}, {8.f,5.f,6.f,7.f}, expected);
    }
    {
        vec3 angles = {20.f,40.f,60.f};
        mat4s mat = glms_mat4_identity();
        glm_euler(angles, mat.raw);
        versors e = glms_mat4_quat(mat);
        Quaternion expected(e.w, e.x, e.y, e.z);
        QuatFromEulerTest({20.f,40.f,60.f}, expected);
    }
    {
        versors q = glms_quat_init(1.f,2.f,3.f,4.f);
        mat4s mat = glms_quat_mat4(q);
        vec3s e;
        glm_euler_angles(mat.raw, e.raw);
        
        Float3 expected(e.x,e.y,e.z);
        Quaternion quat({4.f,1.f,2.f,3.f});
        QuatToEulerTest(quat, expected);
    }
    {
        float angle = PI/2;
        vec3s axs = {1.f,2.f,3.f};
        versors e = glms_quatv(angle, axs);
        
        Float3 axis(axs.x,axs.y,axs.z);
        Quaternion expected(e.w, e.x, e.y, e.z);
        QuatAngleAxisTest(axis, angle, expected);
    }
    {
        float time = 0.5f;
        versors p = glms_quat_init(1.f,2.f,3.f,4.f);
        versors q = glms_quat_init(5.f,6.f,7.f,8.f);
        versors e = glms_quat_slerp(p, q, time);
        
        Quaternion first(p.w, p.x, p.y, p.z);
        Quaternion second(q.w, q.x, q.y, q.z);
        Quaternion expected(e.w, e.x, e.y, e.z);
        QuatSLerpTest(first, second, time, expected);
    }
    {
        float time = 0.5f;
        versors p = glms_quat_init(1.f,2.f,3.f,4.f);
        versors q = glms_quat_init(5.f,6.f,7.f,8.f);
        versors e = glms_quat_nlerp(p, q, time);
        
        Quaternion first(p.w, p.x, p.y, p.z);
        Quaternion second(q.w, q.x, q.y, q.z);
        Quaternion expected(e.w, e.x, e.y, e.z);
        QuatNLerpTest(first, second, time, expected);
    }
    {
        versors p = glms_quat_init(1.f,2.f,3.f,4.f);
        versors q = glms_quat_init(5.f,6.f,7.f,8.f);
        float expected = glms_quat_dot(p, q);
        
        Quaternion first(p.w, p.x, p.y, p.z);
        Quaternion second(q.w, q.x, q.y, q.z);
        QuatDotProductTest(first, second, expected);
    }
    {
        versors p = glms_quat_init(1.f,2.f,3.f,4.f);
        versors q = glms_quat_init(5.f,6.f,7.f,8.f);
        versors e = glms_quat_add(p, q);
        
        Quaternion first(p.w, p.x, p.y, p.z);
        Quaternion second(q.w, q.x, q.y, q.z);
        Quaternion expected(e.w, e.x, e.y, e.z);
        QuatAddTest(first, second, expected);
    }
    TEST_SEQ_END();
#pragma endregion
    
    return 0;
}