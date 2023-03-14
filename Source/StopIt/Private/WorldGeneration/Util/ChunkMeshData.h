#pragma once

#include "CoreMinimal.h"
#include "ChunkMeshData.generated.h"

USTRUCT()
struct FChunkMeshData {
	GENERATED_BODY()


public:
	TArray<FVector> Vertices;
	TArray<int> Triangles;
	TArray<FVector> Normals;
	TArray<FColor> Colors;
	TArray<FVector2D> UVD;
	void Clear();
};

inline void FChunkMeshData::Clear() {
	Vertices.Empty();
	Triangles.Empty();
	Normals.Empty();
	Colors.Empty();
	UVD.Empty();
}