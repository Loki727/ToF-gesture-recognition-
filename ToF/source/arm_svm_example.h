#ifndef ARM_SVM_EXAMPLE_H_
#define ARM_SVM_EXAMPLE_H_

#include "dsp/svm_functions.h"

#define NB_SUPPORT_VECTORS 316
#define VECTOR_DIMENSION 64



void initParams();
int predict(const float * in);

/*
arm_svm_linear_init_f32(arm_svm_linear_instance_f32 *S,
  uint32_t nbOfSupportVectors,
  uint32_t vectorDimension,
  float32_t intercept,
  const float32_t *dualCoefficients,
  const float32_t *supportVectors,
  const int32_t  *classes);

 */

#endif /* ARM_SVM_EXAMPLE_H_ */
