/*
 * Copyright 1993-2020 NVIDIA Corporation.  All rights reserved.
 *
 * NOTICE TO LICENSEE:
 *
 * This source code and/or documentation ("Licensed Deliverables") are
 * subject to NVIDIA intellectual property rights under U.S. and
 * international Copyright laws.
 *
 * These Licensed Deliverables contained herein is PROPRIETARY and
 * CONFIDENTIAL to NVIDIA and is being provided under the terms and
 * conditions of a form of NVIDIA software license agreement by and
 * between NVIDIA and Licensee ("License Agreement") or electronically
 * accepted by Licensee.  Notwithstanding any terms or conditions to
 * the contrary in the License Agreement, reproduction or disclosure
 * of the Licensed Deliverables to any third party without the express
 * written consent of NVIDIA is prohibited.
 *
 * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
 * LICENSE AGREEMENT, NVIDIA MAKES NO REPRESENTATION ABOUT THE
 * SUITABILITY OF THESE LICENSED DELIVERABLES FOR ANY PURPOSE.  IT IS
 * PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY OF ANY KIND.
 * NVIDIA DISCLAIMS ALL WARRANTIES WITH REGARD TO THESE LICENSED
 * DELIVERABLES, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY,
 * NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE.
 * NOTWITHSTANDING ANY TERMS OR CONDITIONS TO THE CONTRARY IN THE
 * LICENSE AGREEMENT, IN NO EVENT SHALL NVIDIA BE LIABLE FOR ANY
 * SPECIAL, INDIRECT, INCIDENTAL, OR CONSEQUENTIAL DAMAGES, OR ANY
 * DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
 * OF THESE LICENSED DELIVERABLES.
 *
 * U.S. Government End Users.  These Licensed Deliverables are a
 * "commercial item" as that term is defined at 48 C.F.R. 2.101 (OCT
 * 1995), consisting of "commercial computer software" and "commercial
 * computer software documentation" as such terms are used in 48
 * C.F.R. 12.212 (SEPT 1995) and is provided to the U.S. Government
 * only as a commercial end item.  Consistent with 48 C.F.R.12.212 and
 * 48 C.F.R. 227.7202-1 through 227.7202-4 (JUNE 1995), all
 * U.S. Government End Users acquire the Licensed Deliverables with
 * only those rights set forth herein.
 *
 * Any use of the Licensed Deliverables in individual and commercial
 * software must include, in the user documentation and internal
 * comments to the code, the above Disclaimer and U.S. Government End
 * Users Notice.
 */

/*   cudnn_adv_train : cuDNN's advanced and experimental features.

*/

#if !defined(CUDNN_ADV_TRAIN_H_)
#define CUDNN_ADV_TRAIN_H_

#include <cuda_runtime.h>
#include <stdint.h>

#include "cudnn_version.h"
#include "cudnn_ops_infer.h"
#include "cudnn_ops_train.h"
#include "cudnn_adv_infer.h"

/* These version numbers are autogenerated, do not edit manually. */
#define CUDNN_ADV_TRAIN_MAJOR 8
#define CUDNN_ADV_TRAIN_MINOR 2
#define CUDNN_ADV_TRAIN_PATCH 4

#if (CUDNN_ADV_TRAIN_MAJOR != CUDNN_MAJOR) || (CUDNN_ADV_TRAIN_MINOR != CUDNN_MINOR) || \
    (CUDNN_ADV_TRAIN_PATCH != CUDNN_PATCHLEVEL)
#error Version mismatch in cuDNN ADV TRAIN!!!
#endif

#if defined(__cplusplus)
extern "C" {
#endif

typedef enum {
    CUDNN_WGRAD_MODE_ADD = 0, /* add partial gradients to wgrad output buffers */
    CUDNN_WGRAD_MODE_SET = 1, /* write partial gradients to wgrad output buffers */
} cudnnWgradMode_t;

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnRNNForwardTraining(cudnnHandle_t handle,
                        const cudnnRNNDescriptor_t rnnDesc,
                        const int seqLength,
                        const cudnnTensorDescriptor_t *xDesc,
                        const void *x,
                        const cudnnTensorDescriptor_t hxDesc,
                        const void *hx,
                        const cudnnTensorDescriptor_t cxDesc,
                        const void *cx,
                        const cudnnFilterDescriptor_t wDesc,
                        const void *w,
                        const cudnnTensorDescriptor_t *yDesc,
                        void *y,
                        const cudnnTensorDescriptor_t hyDesc,
                        void *hy,
                        const cudnnTensorDescriptor_t cyDesc,
                        void *cy,
                        void *workSpace,
                        size_t workSpaceSizeInBytes,
                        void *reserveSpace,
                        size_t reserveSpaceSizeInBytes);

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnRNNBackwardData(cudnnHandle_t handle,
                     const cudnnRNNDescriptor_t rnnDesc,
                     const int seqLength,
                     const cudnnTensorDescriptor_t *yDesc,
                     const void *y,
                     const cudnnTensorDescriptor_t *dyDesc,
                     const void *dy,
                     const cudnnTensorDescriptor_t dhyDesc,
                     const void *dhy,
                     const cudnnTensorDescriptor_t dcyDesc,
                     const void *dcy,
                     const cudnnFilterDescriptor_t wDesc,
                     const void *w,
                     const cudnnTensorDescriptor_t hxDesc,
                     const void *hx,
                     const cudnnTensorDescriptor_t cxDesc,
                     const void *cx,
                     const cudnnTensorDescriptor_t *dxDesc,
                     void *dx,
                     const cudnnTensorDescriptor_t dhxDesc,
                     void *dhx,
                     const cudnnTensorDescriptor_t dcxDesc,
                     void *dcx,
                     void *workSpace,
                     size_t workSpaceSizeInBytes,
                     void *reserveSpace,
                     size_t reserveSpaceSizeInBytes);

cudnnStatus_t CUDNNWINAPI
cudnnRNNBackwardData_v8(cudnnHandle_t handle,
                        cudnnRNNDescriptor_t rnnDesc,
                        const int32_t devSeqLengths[],
                        cudnnRNNDataDescriptor_t yDesc,
                        const void *y,
                        const void *dy,
                        cudnnRNNDataDescriptor_t xDesc,
                        void *dx,
                        cudnnTensorDescriptor_t hDesc,
                        const void *hx,
                        const void *dhy,
                        void *dhx,
                        cudnnTensorDescriptor_t cDesc,
                        const void *cx,
                        const void *dcy,
                        void *dcx,
                        size_t weightSpaceSize,
                        const void *weightSpace,
                        size_t workSpaceSize,
                        void *workSpace,
                        size_t reserveSpaceSize,
                        void *reserveSpace);

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnRNNBackwardWeights(cudnnHandle_t handle,
                        const cudnnRNNDescriptor_t rnnDesc,
                        const int seqLength,
                        const cudnnTensorDescriptor_t *xDesc,
                        const void *x,
                        const cudnnTensorDescriptor_t hxDesc,
                        const void *hx,
                        const cudnnTensorDescriptor_t *yDesc,
                        const void *y,
                        const void *workSpace,
                        size_t workSpaceSizeInBytes,
                        const cudnnFilterDescriptor_t dwDesc,
                        void *dw,
                        const void *reserveSpace,
                        size_t reserveSpaceSizeInBytes);

cudnnStatus_t CUDNNWINAPI
cudnnRNNBackwardWeights_v8(cudnnHandle_t handle,
                           cudnnRNNDescriptor_t rnnDesc,
                           cudnnWgradMode_t addGrad,
                           const int32_t devSeqLengths[],
                           cudnnRNNDataDescriptor_t xDesc,
                           const void *x,
                           cudnnTensorDescriptor_t hDesc,
                           const void *hx,
                           cudnnRNNDataDescriptor_t yDesc,
                           const void *y,
                           size_t weightSpaceSize,
                           void *dweightSpace,
                           size_t workSpaceSize,
                           void *workSpace,
                           size_t reserveSpaceSize,
                           void *reserveSpace);

/* RNN EX API */

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnRNNForwardTrainingEx(cudnnHandle_t handle,
                          const cudnnRNNDescriptor_t rnnDesc,
                          const cudnnRNNDataDescriptor_t xDesc,
                          const void *x,
                          const cudnnTensorDescriptor_t hxDesc,
                          const void *hx,
                          const cudnnTensorDescriptor_t cxDesc,
                          const void *cx,
                          const cudnnFilterDescriptor_t wDesc,
                          const void *w,
                          const cudnnRNNDataDescriptor_t yDesc,
                          void *y,
                          const cudnnTensorDescriptor_t hyDesc,
                          void *hy,
                          const cudnnTensorDescriptor_t cyDesc,
                          void *cy,
                          const cudnnRNNDataDescriptor_t kDesc, /* reserved, should pass NULL */
                          const void *keys,                     /* reserved, should pass NULL */
                          const cudnnRNNDataDescriptor_t cDesc, /* reserved, should pass NULL */
                          void *cAttn,                          /* reserved, should pass NULL */
                          const cudnnRNNDataDescriptor_t iDesc, /* reserved, should pass NULL */
                          void *iAttn,                          /* reserved, should pass NULL */
                          const cudnnRNNDataDescriptor_t qDesc, /* reserved, should pass NULL */
                          void *queries,                        /* reserved, should pass NULL */
                          void *workSpace,
                          size_t workSpaceSizeInBytes,
                          void *reserveSpace,
                          size_t reserveSpaceSizeInBytes);

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnRNNBackwardDataEx(cudnnHandle_t handle,
                       const cudnnRNNDescriptor_t rnnDesc,
                       const cudnnRNNDataDescriptor_t yDesc,
                       const void *y,
                       const cudnnRNNDataDescriptor_t dyDesc,
                       const void *dy,
                       const cudnnRNNDataDescriptor_t dcDesc, /* reserved, should pass NULL */
                       const void *dcAttn,                    /* reserved, should pass NULL */
                       const cudnnTensorDescriptor_t dhyDesc,
                       const void *dhy,
                       const cudnnTensorDescriptor_t dcyDesc,
                       const void *dcy,
                       const cudnnFilterDescriptor_t wDesc,
                       const void *w,
                       const cudnnTensorDescriptor_t hxDesc,
                       const void *hx,
                       const cudnnTensorDescriptor_t cxDesc,
                       const void *cx,
                       const cudnnRNNDataDescriptor_t dxDesc,
                       void *dx,
                       const cudnnTensorDescriptor_t dhxDesc,
                       void *dhx,
                       const cudnnTensorDescriptor_t dcxDesc,
                       void *dcx,
                       const cudnnRNNDataDescriptor_t dkDesc, /* reserved, should pass NULL */
                       void *dkeys,                           /* reserved, should pass NULL */
                       void *workSpace,
                       size_t workSpaceSizeInBytes,
                       void *reserveSpace,
                       size_t reserveSpaceSizeInBytes);

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnRNNBackwardWeightsEx(cudnnHandle_t handle,
                          const cudnnRNNDescriptor_t rnnDesc,
                          const cudnnRNNDataDescriptor_t xDesc,
                          const void *x,
                          const cudnnTensorDescriptor_t hxDesc,
                          const void *hx,
                          const cudnnRNNDataDescriptor_t yDesc,
                          const void *y,
                          void *workSpace,
                          size_t workSpaceSizeInBytes,
                          const cudnnFilterDescriptor_t dwDesc,
                          void *dw,
                          void *reserveSpace,
                          size_t reserveSpaceSizeInBytes);

/* RNN FIND API */

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnGetRNNForwardTrainingAlgorithmMaxCount(cudnnHandle_t handle, const cudnnRNNDescriptor_t rnnDesc, int *count);

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnFindRNNForwardTrainingAlgorithmEx(cudnnHandle_t handle,
                                       const cudnnRNNDescriptor_t rnnDesc,
                                       const int seqLength,
                                       const cudnnTensorDescriptor_t *xDesc,
                                       const void *x,
                                       const cudnnTensorDescriptor_t hxDesc,
                                       const void *hx,
                                       const cudnnTensorDescriptor_t cxDesc,
                                       const void *cx,
                                       const cudnnFilterDescriptor_t wDesc,
                                       const void *w,
                                       const cudnnTensorDescriptor_t *yDesc,
                                       void *y,
                                       const cudnnTensorDescriptor_t hyDesc,
                                       void *hy,
                                       const cudnnTensorDescriptor_t cyDesc,
                                       void *cy,
                                       const float findIntensity,
                                       const int requestedAlgoCount,
                                       int *returnedAlgoCount,
                                       cudnnAlgorithmPerformance_t *perfResults,
                                       void *workspace,
                                       size_t workSpaceSizeInBytes,
                                       void *reserveSpace,
                                       size_t reserveSpaceSizeInBytes);

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnGetRNNBackwardDataAlgorithmMaxCount(cudnnHandle_t handle, const cudnnRNNDescriptor_t rnnDesc, int *count);

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnFindRNNBackwardDataAlgorithmEx(cudnnHandle_t handle,
                                    const cudnnRNNDescriptor_t rnnDesc,
                                    const int seqLength,
                                    const cudnnTensorDescriptor_t *yDesc,
                                    const void *y,
                                    const cudnnTensorDescriptor_t *dyDesc,
                                    const void *dy,
                                    const cudnnTensorDescriptor_t dhyDesc,
                                    const void *dhy,
                                    const cudnnTensorDescriptor_t dcyDesc,
                                    const void *dcy,
                                    const cudnnFilterDescriptor_t wDesc,
                                    const void *w,
                                    const cudnnTensorDescriptor_t hxDesc,
                                    const void *hx,
                                    const cudnnTensorDescriptor_t cxDesc,
                                    const void *cx,
                                    const cudnnTensorDescriptor_t *dxDesc,
                                    void *dx,
                                    const cudnnTensorDescriptor_t dhxDesc,
                                    void *dhx,
                                    const cudnnTensorDescriptor_t dcxDesc,
                                    void *dcx,
                                    const float findIntensity,
                                    const int requestedAlgoCount,
                                    int *returnedAlgoCount,
                                    cudnnAlgorithmPerformance_t *perfResults,
                                    void *workspace,
                                    size_t workSpaceSizeInBytes,
                                    void *reserveSpace,
                                    size_t reserveSpaceSizeInBytes);

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnGetRNNBackwardWeightsAlgorithmMaxCount(cudnnHandle_t handle, const cudnnRNNDescriptor_t rnnDesc, int *count);

CUDNN_DEPRECATED cudnnStatus_t CUDNNWINAPI
cudnnFindRNNBackwardWeightsAlgorithmEx(cudnnHandle_t handle,
                                       const cudnnRNNDescriptor_t rnnDesc,
                                       const int seqLength,
                                       const cudnnTensorDescriptor_t *xDesc,
                                       const void *x,
                                       const cudnnTensorDescriptor_t hxDesc,
                                       const void *hx,
                                       const cudnnTensorDescriptor_t *yDesc,
                                       const void *y,
                                       const float findIntensity,
                                       const int requestedAlgoCount,
                                       int *returnedAlgoCount,
                                       cudnnAlgorithmPerformance_t *perfResults,
                                       const void *workspace,
                                       size_t workSpaceSizeInBytes,
                                       const cudnnFilterDescriptor_t dwDesc,
                                       void *dw,
                                       const void *reserveSpace,
                                       size_t reserveSpaceSizeInBytes);

cudnnStatus_t CUDNNWINAPI
cudnnMultiHeadAttnBackwardData(cudnnHandle_t handle,
                               const cudnnAttnDescriptor_t attnDesc,
                               const int loWinIdx[],
                               const int hiWinIdx[],
                               const int devSeqLengthsDQDO[],
                               const int devSeqLengthsDKDV[],
                               const cudnnSeqDataDescriptor_t doDesc,
                               const void *dout,
                               const cudnnSeqDataDescriptor_t dqDesc,
                               void *dqueries,
                               const void *queries,
                               const cudnnSeqDataDescriptor_t dkDesc,
                               void *dkeys,
                               const void *keys,
                               const cudnnSeqDataDescriptor_t dvDesc,
                               void *dvalues,
                               const void *values,
                               size_t weightSizeInBytes,
                               const void *weights,
                               size_t workSpaceSizeInBytes,
                               void *workSpace,
                               size_t reserveSpaceSizeInBytes,
                               void *reserveSpace);

cudnnStatus_t CUDNNWINAPI
cudnnMultiHeadAttnBackwardWeights(cudnnHandle_t handle,
                                  const cudnnAttnDescriptor_t attnDesc,
                                  cudnnWgradMode_t addGrad,
                                  const cudnnSeqDataDescriptor_t qDesc,
                                  const void *queries,
                                  const cudnnSeqDataDescriptor_t kDesc,
                                  const void *keys,
                                  const cudnnSeqDataDescriptor_t vDesc,
                                  const void *values,
                                  const cudnnSeqDataDescriptor_t doDesc,
                                  const void *dout,
                                  size_t weightSizeInBytes,
                                  const void *weights,
                                  void *dweights,
                                  size_t workSpaceSizeInBytes,
                                  void *workSpace,
                                  size_t reserveSpaceSizeInBytes,
                                  void *reserveSpace);

/*
* CTC (Connectionist Temporal Classification) loss descriptor create/destory/set/get functions
*/
/* Input normalization mode for loss function */
typedef enum {
    CUDNN_LOSS_NORMALIZATION_NONE    = 0,
    CUDNN_LOSS_NORMALIZATION_SOFTMAX = 1,
} cudnnLossNormalizationMode_t;

cudnnStatus_t CUDNNWINAPI
cudnnCreateCTCLossDescriptor(cudnnCTCLossDescriptor_t *ctcLossDesc);

cudnnStatus_t CUDNNWINAPI
cudnnSetCTCLossDescriptor(cudnnCTCLossDescriptor_t ctcLossDesc, cudnnDataType_t compType);

cudnnStatus_t CUDNNWINAPI
cudnnSetCTCLossDescriptorEx(cudnnCTCLossDescriptor_t ctcLossDesc,
                            cudnnDataType_t compType,
                            cudnnLossNormalizationMode_t normMode,
                            cudnnNanPropagation_t gradMode);

cudnnStatus_t CUDNNWINAPI
cudnnSetCTCLossDescriptor_v8(cudnnCTCLossDescriptor_t ctcLossDesc,
                             cudnnDataType_t compType,
                             cudnnLossNormalizationMode_t normMode,
                             cudnnNanPropagation_t gradMode,
                             int maxLabelLength);

cudnnStatus_t CUDNNWINAPI
cudnnGetCTCLossDescriptor(cudnnCTCLossDescriptor_t ctcLossDesc, cudnnDataType_t *compType);

cudnnStatus_t CUDNNWINAPI
cudnnGetCTCLossDescriptorEx(cudnnCTCLossDescriptor_t ctcLossDesc,
                            cudnnDataType_t *compType,
                            cudnnLossNormalizationMode_t *normMode,
                            cudnnNanPropagation_t *gradMode);

cudnnStatus_t CUDNNWINAPI
cudnnGetCTCLossDescriptor_v8(cudnnCTCLossDescriptor_t ctcLossDesc,
                             cudnnDataType_t *compType,
                             cudnnLossNormalizationMode_t *normMode,
                             cudnnNanPropagation_t *gradMode,
                             int *maxLabelLength);

cudnnStatus_t CUDNNWINAPI
cudnnDestroyCTCLossDescriptor(cudnnCTCLossDescriptor_t ctcLossDesc);

/* return the ctc costs and gradients, given the probabilities and labels */
cudnnStatus_t CUDNNWINAPI
cudnnCTCLoss(
    cudnnHandle_t handle,
    const cudnnTensorDescriptor_t
        probsDesc,     /* Tensor descriptor for probabilities, the dimensions are T,N,A (T is the timing steps, N is the
                          mini batch size, A is the alphabet size)  */
    const void *probs, /* probabilities after softmax, in GPU memory */
    const int hostLabels[],                      /* labels, in CPU memory */
    const int hostLabelLengths[],                /* the length of each label, in CPU memory */
    const int hostInputLengths[],                /* the lengths of timing steps in each batch, in CPU memory */
    void *costs,                                 /* the returned costs of CTC, in GPU memory */
    const cudnnTensorDescriptor_t gradientsDesc, /* Tensor descriptor for gradients, the dimensions are T,N,A */
    void *gradients,         /* the returned CTC gradients, in GPU memory, to compute costs only, set it to NULL */
    cudnnCTCLossAlgo_t algo, /* algorithm selected, supported now 0 and 1 */
    cudnnCTCLossDescriptor_t ctcLossDesc,
    void *workspace,              /* pointer to the workspace, in GPU memory */
    size_t workSpaceSizeInBytes); /* size of the workspace */

/* return the ctc costs and gradients, given the probabilities and labels */
cudnnStatus_t CUDNNWINAPI
cudnnCTCLoss_v8(
    cudnnHandle_t handle,
    cudnnCTCLossAlgo_t algo, /* algorithm selected, supported now 0 and 1 */
    cudnnCTCLossDescriptor_t ctcLossDesc,
    const cudnnTensorDescriptor_t
        probsDesc,     /* Tensor descriptor for probabilities, the dimensions are T,N,A (T is the timing steps, N is the
                          mini batch size, A is the alphabet size)  */
    const void *probs, /* probabilities after softmax, in GPU memory */
    const int labels[],                          /* labels, in GPU memory */
    const int labelLengths[],                    /* the length of each label, in GPU memory */
    const int inputLengths[],                    /* the lengths of timing steps in each batch, in GPU memory */
    void *costs,                                 /* the returned costs of CTC, in GPU memory */
    const cudnnTensorDescriptor_t gradientsDesc, /* Tensor descriptor for gradients, the dimensions are T,N,A */
    void *gradients,             /* the returned CTC gradients, in GPU memory, to compute costs only, set it to NULL */
    size_t workSpaceSizeInBytes, /* size of the workspace */
    void *workspace);            /* pointer to the workspace, in GPU memory */

/* return the workspace size needed for ctc */
cudnnStatus_t CUDNNWINAPI
cudnnGetCTCLossWorkspaceSize(
    cudnnHandle_t handle,
    const cudnnTensorDescriptor_t probsDesc, /* Tensor descriptor for probabilities, the dimensions are T,N,A (T is the
                                                timing steps, N is the mini batch size, A is the alphabet size) */
    const cudnnTensorDescriptor_t gradientsDesc, /* Tensor descriptor for gradients, the
                                                    dimensions are T,N,A. To compute costs
                                                    only, set it to NULL */
    const int *labels,                           /* labels, in CPU memory */
    const int *labelLengths,                     /* the length of each label, in CPU memory */
    const int *inputLengths,                     /* the lengths of timing steps in each batch, in CPU memory */
    cudnnCTCLossAlgo_t algo,                     /* algorithm selected, supported now 0 and 1 */
    cudnnCTCLossDescriptor_t ctcLossDesc,
    size_t *sizeInBytes); /* pointer to the returned workspace size */

/* return the workspace size needed for ctc */
cudnnStatus_t CUDNNWINAPI
cudnnGetCTCLossWorkspaceSize_v8(
    cudnnHandle_t handle,
    cudnnCTCLossAlgo_t algo, /* algorithm selected, supported now 0 and 1 */
    cudnnCTCLossDescriptor_t ctcLossDesc,
    const cudnnTensorDescriptor_t probsDesc, /* Tensor descriptor for probabilities, the dimensions are T,N,A (T is the
                                                timing steps, N is the mini batch size, A is the alphabet size) */
    const cudnnTensorDescriptor_t gradientsDesc, /* Tensor descriptor for gradients, the
                                                    dimensions are T,N,A. To compute costs
                                                    only, set it to NULL */
    size_t *sizeInBytes);                        /* pointer to the returned workspace size */

/*
 * \brief Cross-library version checker.
 * This function is implemented differently in each sub-library. Each sublib
 * checks whether its own version matches that of its dependencies.
 * \returns CUDNN_STATUS_SUCCESS if the version check passes,
 *          CUDNN_STATUS_VERSION_MISMATCH if the versions are inconsistent.
 */
cudnnStatus_t CUDNNWINAPI
cudnnAdvTrainVersionCheck(void);

#if defined(__cplusplus)
}
#endif

#endif /* CUDNN_ADV_TRAIN_H_ */
