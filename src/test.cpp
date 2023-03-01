#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include <string.h>

#include <cglm/vec2.h>
#include <cglm/vec3.h>
#include <cglm/types-struct.h>

#define REDFOXMATHS_IMPLEMENTATION
#include <RedFoxMaths.hpp>
using namespace RedFoxMaths;

#include <test.hpp>

int main() 
{
    // TODO(vegasword): Replace every vecX by vecXs
    // TODO(vegasword): Random float macro
    // TODO(vegasword): Iterations (for loop for each test to stress test)
    
#pragma region Float2Test
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
        vec2 expected = {2.f,3.f};
        glm_vec2_normalize(expected);
        Float2 in({2.f,3.f});
        Float2NormalizeTest(in, {expected[0],expected[1]});
    }
    {
        vec2 expected = {0};
        glm_vec2_lerp(new(vec2){2.f,3.f}, new(vec2){4.f,5.f}, 0.5f, expected);
        Float2LerpTest({2.f,3.f}, {4.f,5.f}, 0.5f, {expected[0],expected[1]});
    }
    {
        vec2 expected = {0};
        glm_vec2_add(new(vec2){2.f,3.f}, new(vec2){4.f,5.f}, expected);
        Float2AddTest({2.f,3.f}, {4.f,5.f}, {expected[0],expected[1]});
    }
    {
        vec2 expected = {0};
        glm_vec2_sub(new(vec2){2.f,3.f}, new(vec2){4.f,5.f}, expected);
        Float2SubTest({2.f,3.f}, {4.f,5.f}, {expected[0],expected[1]});
    }
    {
        vec2 expected = {0};
        glm_vec2_scale(new(vec2){2.f,3.f}, 4.f, expected);
        Float2MulSTest({2.f,3.f}, 4.f, {expected[0],expected[1]});
    }
    {
        vec2 expected = {0};
        glm_vec2_divs(new(vec2){2.f,3.f}, 4.f, expected);
        Float2DivSTest({2.f,3.f}, 4.f, {expected[0],expected[1]});
    }
#pragma endregion
    
#pragma region Float3Test
    {
        vec3 expected = {0};
        glm_vec3_cross(new(vec3){2.f,3.f,4.f}, new(vec3){7.f,8.f,9.f}, expected);
        Float3CrossProductTest({2.f,3.f,4.f}, {7.f,8.f,9.f}, {expected[0],expected[1],expected[2]});
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
        vec3 expected = {2.f,3.f,4.f};
        glm_vec3_normalize(expected);
        Float3 in({2.f,3.f,4.f});
        Float3NormalizeTest(in, {expected[0],expected[1],expected[2]});
    }
    {
        vec3 expected = {0};
        glm_vec3_lerp(new(vec3){2.f,3.f,4.f}, new(vec3){4.f,5.f,6.f}, 0.5f, expected);
        Float3LerpTest({2.f,3.f,4.f}, {4.f,5.f,6.f}, 0.5f, {expected[0],expected[1],expected[2]});
    }
    {
        vec3 expected = {0};
        glm_vec3_add(new(vec3){2.f,3.f,4.f}, new(vec3){4.f,5.f,6.f}, expected);
        Float3AddTest({2.f,3.f,4.f}, {4.f,5.f,6.f}, {expected[0],expected[1],expected[2]});
    }
    {
        vec3 expected = {0};
        glm_vec3_sub(new(vec3){2.f,3.f,4.f}, new(vec3){4.f,5.f,6.f}, expected);
        Float3SubTest({2.f,3.f,4.f}, {4.f,5.f,6.f}, {expected[0],expected[1],expected[2]});
    }
    {
        vec2 expected = {0};
        glm_vec3_scale(new(vec3){2.f,3.f,4.f}, 4.f, expected);
        Float3MulSTest({2.f,3.f,4.f}, 4.f, {expected[0],expected[1],expected[2]});
    }
    {
        vec3 expected = {0};
        glm_vec3_divs(new(vec3){2.f,3.f,4.f}, 4.f, expected);
        Float3DivSTest({2.f,3.f,4.f}, 4.f, {expected[0],expected[1],expected[2]});
    }
#pragma endregion
    
#pragma region Float4Test
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
        vec4 expected = {2.f,3.f,4.f,5.f};
        glm_vec4_normalize(expected);
        Float4 in({2.f,3.f,4.f,5.f});
        Float4NormalizeTest(in, {expected[0],expected[1],expected[2],expected[3]});
    }
    {
        vec4 expected = {0};
        glm_vec4_add(new(vec4){2.f,3.f,4.f,5.f}, new(vec4){4.f,5.f,6.f,7.f}, expected);
        Float4AddTest({2.f,3.f,4.f,5.f}, {4.f,5.f,6.f,7.f}, {expected[0],expected[1],expected[2],expected[3]});
    }
    {
        vec4 expected = {0};
        glm_vec4_sub(new(vec4){2.f,3.f,4.f,5.f}, new(vec4){4.f,5.f,6.f,7.f}, expected);
        Float4SubTest({2.f,3.f,4.f,5.f}, {4.f,5.f,6.f,7.f}, {expected[0],expected[1],expected[2],expected[3]});
    }
    {
        vec4 expected = {0};
        glm_vec4_scale(new(vec4){2.f,3.f,4.f,5.f}, 4.f, expected);
        Float4MulSTest({2.f,3.f,4.f,5.f}, 4.f, {expected[0],expected[1],expected[2],expected[3]});
    }
    {
        vec4 expected = {0};
        glm_vec4_divs(new(vec4){2.f,3.f,4.f,5.f}, 4.f, expected);
        Float4DivSTest({2.f,3.f,4.f,5.f}, 4.f, {expected[0],expected[1],expected[2],expected[3]});
    }
#pragma endregion
    
    return 0;
}