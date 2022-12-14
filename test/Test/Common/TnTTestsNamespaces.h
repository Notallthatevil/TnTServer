#pragma once

#ifndef TEST_NAMESPACE
#   error Define TEST_NAMESPACE to use for testing!
#endif   // !TEST_NAMESPACE

#define NAMESPACE_GTEST_TEST_CLASS_NAME_(namespace_name, test_case_name, test_name) namespace_name##_##test_case_name##_##test_name##_Test

#define TNTENGINE_TESTS_XSTRINGIFY(a) TNTENGINE_TESTS_STRINGIFY(a)
#define TNTENGINE_TESTS_STRINGIFY(a)  #a
// A copy of GTEST_TEST_, but with handling for namespace name.

#define NAMESPACE_GTEST_TEST_(namespace_name, test_case_name, test_name, parent_class, parent_id)                                                                           \
   class NAMESPACE_GTEST_TEST_CLASS_NAME_(namespace_name, test_case_name, test_name) : public parent_class {                                                                \
     public:                                                                                                                                                                \
      NAMESPACE_GTEST_TEST_CLASS_NAME_(namespace_name, test_case_name, test_name)() {}                                                                                      \
                                                                                                                                                                            \
     private:                                                                                                                                                               \
      virtual void                                 TestBody();                                                                                                              \
      static ::testing::TestInfo *const test_info_ GTEST_ATTRIBUTE_UNUSED_;                                                                                                 \
      GTEST_DISALLOW_COPY_AND_ASSIGN_(NAMESPACE_GTEST_TEST_CLASS_NAME_(namespace_name, test_case_name, test_name));                                                         \
   };                                                                                                                                                                       \
                                                                                                                                                                            \
   ::testing::TestInfo *const NAMESPACE_GTEST_TEST_CLASS_NAME_(namespace_name, test_case_name, test_name)::test_info_ =                                                     \
       ::testing::internal::MakeAndRegisterTestInfo(TNTENGINE_TESTS_XSTRINGIFY(TEST_NAMESPACE) "_" #test_case_name,                                                         \
                                                    #test_name,                                                                                                             \
                                                    NULL,                                                                                                                   \
                                                    NULL, /* <-- Defines the test as "Namespace.Classname" */                                                               \
                                                    ::testing::internal::CodeLocation(__FILE__, __LINE__),                                                                  \
                                                    (parent_id),                                                                                                            \
                                                    parent_class::SetUpTestCase,                                                                                            \
                                                    parent_class::TearDownTestCase,                                                                                         \
                                                    new ::testing::internal::TestFactoryImpl<NAMESPACE_GTEST_TEST_CLASS_NAME_(namespace_name, test_case_name, test_name)>); \
   void NAMESPACE_GTEST_TEST_CLASS_NAME_(namespace_name, test_case_name, test_name)::TestBody()

#define NAMESPACE_TEST(test_case_name, test_name) NAMESPACE_GTEST_TEST_(TEST_NAMESPACE, test_case_name, test_name, ::testing::Test, ::testing::internal::GetTestTypeId())

#include "Common/TnTTestDefines.h"
