// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "WorldGeneration/Util/ChunkMeshData.h"
#include "WorldGeneration/Util/Enums.h"

#include "ChunkBase.generated.h"

class FastNoiseLite;
class UProceduralMeshComponent;

UCLASS()
class AChunkBase : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunkBase();

	UPROPERTY(EditDefaultsOnly, Category = "Chunk")
	int Size;

	TObjectPtr<UMaterialInterface> Material;
	float Frequency;

	
	EGenerationType GenerationType;

	UFUNCTION(BlueprintCallable, Category = "Chunk")
	void ModifyVoxel(const FIntVector Position, const EBlock Block);
	
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	virtual void Setup() PURE_VIRTUAL(AChunkBase::Setup);
	virtual void Generate2DHeightMap(const FVector Position) PURE_VIRTUAL(AChunkBase::Generate2DHeightMap);
	virtual void Generate3DHeightMap(const FVector Position) PURE_VIRTUAL(AChunkBase::Generate3DHeightMap);
	virtual void GenerateMesh() PURE_VIRTUAL(AChunkBase::GenerateMesh);
	
	virtual void ModifyVoxelData(const FIntVector Position, EBlock Block) PURE_VIRTUAL(AChunkBase::ModifyVoxelData); 

	TObjectPtr<UProceduralMeshComponent> Mesh;
	FastNoiseLite* Noise;
	FChunkMeshData MeshData;
	int VertexCount = 0;

private:
	void ApplyMesh() const;
	void ClearMesh();
	void GenerateHeightMap();
};

