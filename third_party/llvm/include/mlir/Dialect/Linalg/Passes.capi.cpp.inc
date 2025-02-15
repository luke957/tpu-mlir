/* Autogenerated by mlir-tblgen; don't manually edit. */
//===----------------------------------------------------------------------===//
// Linalg Group Registration
//===----------------------------------------------------------------------===//

void mlirRegisterLinalgPasses() {
  registerLinalgPasses();
}

MlirPass mlirCreateLinalgConvertElementwiseToLinalg() {
  return wrap(mlir::createConvertElementwiseToLinalgPass().release());
}
void mlirRegisterLinalgConvertElementwiseToLinalg() {
  registerConvertElementwiseToLinalg();
}


MlirPass mlirCreateLinalgLinalgBufferize() {
  return wrap(mlir::createLinalgBufferizePass().release());
}
void mlirRegisterLinalgLinalgBufferize() {
  registerLinalgBufferize();
}


MlirPass mlirCreateLinalgLinalgDetensorize() {
  return wrap(mlir::createLinalgDetensorizePass().release());
}
void mlirRegisterLinalgLinalgDetensorize() {
  registerLinalgDetensorize();
}


MlirPass mlirCreateLinalgLinalgElementwiseOpFusion() {
  return wrap(mlir::createLinalgElementwiseOpFusionPass().release());
}
void mlirRegisterLinalgLinalgElementwiseOpFusion() {
  registerLinalgElementwiseOpFusion();
}


MlirPass mlirCreateLinalgLinalgFoldUnitExtentDims() {
  return wrap(mlir::createLinalgFoldUnitExtentDimsPass().release());
}
void mlirRegisterLinalgLinalgFoldUnitExtentDims() {
  registerLinalgFoldUnitExtentDims();
}


MlirPass mlirCreateLinalgLinalgGeneralization() {
  return wrap(mlir::createLinalgGeneralizationPass().release());
}
void mlirRegisterLinalgLinalgGeneralization() {
  registerLinalgGeneralization();
}


MlirPass mlirCreateLinalgLinalgInitTensorToAllocTensor() {
  return wrap(mlir::createLinalgInitTensorToAllocTensorPass().release());
}
void mlirRegisterLinalgLinalgInitTensorToAllocTensor() {
  registerLinalgInitTensorToAllocTensor();
}


MlirPass mlirCreateLinalgLinalgInlineScalarOperands() {
  return wrap(mlir::createLinalgInlineScalarOperandsPass().release());
}
void mlirRegisterLinalgLinalgInlineScalarOperands() {
  registerLinalgInlineScalarOperands();
}


MlirPass mlirCreateLinalgLinalgLowerToAffineLoops() {
  return wrap(mlir::createConvertLinalgToAffineLoopsPass().release());
}
void mlirRegisterLinalgLinalgLowerToAffineLoops() {
  registerLinalgLowerToAffineLoops();
}


MlirPass mlirCreateLinalgLinalgLowerToLoops() {
  return wrap(mlir::createConvertLinalgToLoopsPass().release());
}
void mlirRegisterLinalgLinalgLowerToLoops() {
  registerLinalgLowerToLoops();
}


MlirPass mlirCreateLinalgLinalgLowerToParallelLoops() {
  return wrap(mlir::createConvertLinalgToParallelLoopsPass().release());
}
void mlirRegisterLinalgLinalgLowerToParallelLoops() {
  registerLinalgLowerToParallelLoops();
}


MlirPass mlirCreateLinalgLinalgNamedOpConversion() {
  return wrap(mlir::createLinalgNamedOpConversionPass().release());
}
void mlirRegisterLinalgLinalgNamedOpConversion() {
  registerLinalgNamedOpConversion();
}


MlirPass mlirCreateLinalgLinalgStrategyDecomposePass() {
  return wrap(mlir::createLinalgStrategyDecomposePass().release());
}
void mlirRegisterLinalgLinalgStrategyDecomposePass() {
  registerLinalgStrategyDecomposePass();
}


MlirPass mlirCreateLinalgLinalgStrategyLowerVectorsPass() {
  return wrap(mlir::createLinalgStrategyLowerVectorsPass().release());
}
void mlirRegisterLinalgLinalgStrategyLowerVectorsPass() {
  registerLinalgStrategyLowerVectorsPass();
}


MlirPass mlirCreateLinalgLinalgStrategyPadPass() {
  return wrap(mlir::createLinalgStrategyPadPass().release());
}
void mlirRegisterLinalgLinalgStrategyPadPass() {
  registerLinalgStrategyPadPass();
}


MlirPass mlirCreateLinalgLinalgStrategyPeelPass() {
  return wrap(mlir::createLinalgStrategyPeelPass().release());
}
void mlirRegisterLinalgLinalgStrategyPeelPass() {
  registerLinalgStrategyPeelPass();
}


MlirPass mlirCreateLinalgLinalgStrategyRemoveMarkersPass() {
  return wrap(mlir::createLinalgStrategyRemoveMarkersPass().release());
}
void mlirRegisterLinalgLinalgStrategyRemoveMarkersPass() {
  registerLinalgStrategyRemoveMarkersPass();
}


MlirPass mlirCreateLinalgLinalgStrategyTileAndFusePass() {
  return wrap(mlir::createLinalgStrategyTileAndFusePass().release());
}
void mlirRegisterLinalgLinalgStrategyTileAndFusePass() {
  registerLinalgStrategyTileAndFusePass();
}


MlirPass mlirCreateLinalgLinalgStrategyTilePass() {
  return wrap(mlir::createLinalgStrategyTilePass().release());
}
void mlirRegisterLinalgLinalgStrategyTilePass() {
  registerLinalgStrategyTilePass();
}


MlirPass mlirCreateLinalgLinalgStrategyVectorizePass() {
  return wrap(mlir::createLinalgStrategyVectorizePass().release());
}
void mlirRegisterLinalgLinalgStrategyVectorizePass() {
  registerLinalgStrategyVectorizePass();
}


MlirPass mlirCreateLinalgLinalgTilingPass() {
  return wrap(mlir::createLinalgTilingPass().release());
}
void mlirRegisterLinalgLinalgTilingPass() {
  registerLinalgTilingPass();
}

