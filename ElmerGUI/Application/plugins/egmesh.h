/* femknot.h */
/* This module includes utilities that operate on single knots. It builds
   structures where the knots can be saved, it finds boundaries, 
   copies knots from structures to others and destroys structures that
   become obsolite. The routines mostly operate on structures 
   FemType and BoundaryType. */

int GetElementDimension(int elementtype);
int GetMaxElementType(struct FemType *data);
int GetMinElementType(struct FemType *data);
int GetMaxElementDimension(struct FemType *data);
void GetElementInfo(int element,struct FemType *data,
		    Real *globalcoord,int *ind,int *material);
void GetElementSide(int element,int side,int normal,
		    struct FemType *data,int *ind,int *sideelemtype);
void NumberVariables(struct FemType *data,int variable);
int CalculateIndexwidth(struct FemType *data,int indxis,int *indx);

void InitializeKnots(struct FemType *data);
void AllocateKnots(struct FemType *data);
void CreateKnots(struct GridType *grid,struct CellType *cell,
		 struct FemType *data,int noknots,int info);

int CreateVariable(struct FemType *data,int variable,int unknowns,
		   Real value,const char *variablename,int eorder);
void DestroyKnots(struct FemType *data);
int FindParentSide(struct FemType *data,struct BoundaryType *bound,
		   int sideelem,int sideelemtype,int *sideind);
int CreateBoundary(struct CellType *cell,struct FemType *data,
		   struct BoundaryType *bound,int material1,int material2,
		   int solidmat,int boundarytype,int info);
int CreateAllBoundaries(struct CellType *cell,struct FemType *data,
			struct BoundaryType *bound,int info);
int AllocateBoundary(struct BoundaryType *bound,int size);
int DestroyBoundary(struct BoundaryType *bound);
int CreatePoints(struct CellType *cell,struct FemType *data,
		 struct BoundaryType *bound,
		 int param1,int param2,int pointmode,int pointtype,int info);
int SetDiscontinuousBoundary(struct FemType *data,struct BoundaryType *bound,
			     int boundtype,int endnodes,int info);
int SetConnectedBoundary(struct FemType *data,struct BoundaryType *bound,
			 int bctype,int connecttype,int info);
int FindCorners(struct GridType *grid,struct CellType *cell,
		struct FemType *data,int info);

int ConstantToBilinear(struct FemType *data,int var1,int var2);
int ElementsToTriangles(struct FemType *data,struct BoundaryType *bound,
			Real critangle,int info);
int IncreaseElementOrder(struct FemType *data,int info);
int PolarCoordinates(struct FemType *data,Real rad,int info);
int CylinderCoordinates(struct FemType *data,int info);
int UniteMeshes(struct FemType *data1,struct FemType *data2,
		struct BoundaryType *bound1,struct BoundaryType *bound2,
		int info);
int CloneMeshes(struct FemType *data,struct BoundaryType *bound,
		int *ncopies,Real *meshsize,int diffmats,int info);
int MirrorMeshes(struct FemType *data,struct BoundaryType *bound,
		 int *symmaxis,int diffmats,Real *meshsize,int symmbound,int info);
void ReorderElements(struct FemType *data,struct BoundaryType *bound,
		    int manual,Real corder[],int info);
int RemoveUnusedNodes(struct FemType *data,int info);
void RenumberBoundaryTypes(struct FemType *data,struct BoundaryType *bound,
			   int renumber, int bcoffset, int info);
void RenumberMaterialTypes(struct FemType *data,struct BoundaryType *bound,int info);
void CreateKnotsExtruded(struct FemType *dataxy,struct BoundaryType *boundxy,
			 struct GridType *grid,
			 struct FemType *data,struct BoundaryType *bound,
			 int info);
void ReduceElementOrder(struct FemType *data,int matmin,int matmax);
void IsoparametricElements(struct FemType *data,struct BoundaryType *bound,
			   int bcstoo,int info);
void MergeElements(struct FemType *data,struct BoundaryType *bound,
		   int manual,Real corder[],Real eps,int mergebounds,int info);
void MergeBoundaries(struct FemType *data,struct BoundaryType *bound,int *doubles,int info);
void SeparateCartesianBoundaries(struct FemType *data,struct BoundaryType *bound,int info);
void ElementsToBoundaryConditions(struct FemType *data,
				  struct BoundaryType *bound,int retainorphans,int info);
int FindPeriodicNodes(struct FemType *data,int periodicdim[],int info);
int FindNewBoundaries(struct FemType *data,struct BoundaryType *bound,
		      int *boundnodes,int suggesttype,int dimred,int info);
int FindBulkBoundary(struct FemType *data,int mat1,int mat2,
		     int *boundnodes,int *noboundnodes,int info);
int FindBoundaryBoundary(struct FemType *data,struct BoundaryType *bound,int mat1,int mat2,
			 int *boundnodes,int *noboundnodes,int info);
int CreateBoundaryLayer(struct FemType *data,struct BoundaryType *bound,
			int nolayers, int *layerbounds, int *layernumber,
			Real *layerratios, Real *layerthickness, int *layerparents,
			int maxfilters, Real layereps, int info);
int CreateBoundaryLayerDivide(struct FemType *data,struct BoundaryType *bound,
			      int nolayers, int *layerbounds, int *layernumber,
			      Real *layerratios, Real *layerthickness, int *layerparents,int info);
int RotateTranslateScale(struct FemType *data,struct ElmergridType *eg,int info);
int RemoveLowerDimensionalBoundaries(struct FemType *data,struct BoundaryType *bound,int info);

int CreateDualGraph(struct FemType *data,int full,int info);
int DestroyDualGraph(struct FemType *data,int info);
int CreateInverseTopology(struct FemType *data,int info);
int MeshTypeStatistics(struct FemType *data,int info);
int SideAndBulkMappings(struct FemType *data,struct BoundaryType *bound,struct ElmergridType *eg,int info);
int SideAndBulkBoundaries(struct FemType *data,struct BoundaryType *bound,struct ElmergridType *eg,int info);
