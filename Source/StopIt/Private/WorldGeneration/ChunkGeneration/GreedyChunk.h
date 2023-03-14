// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChunkBase.h"
#include "WorldGeneration/Util/Enums.h"
#include "GreedyChunk.generated.h"

class FastNoiseLite;
class UProceduralMeshComponent;

UCLASS()
class AGreedyChunk : public AChunkBase {
	GENERATED_BODY()

	struct FMask {
		EBlock Block;
		int Normal;
		
	};
	

protected:
	// Called when the game starts or when spawned
	virtual void Setup() override;
	virtual void Generate2DHeightMap(FVector Position) override;
	virtual void Generate3DHeightMap(FVector Position) override;
	virtual void GenerateMesh() override;
	virtual void ModifyVoxelData(const FIntVector Position, EBlock Block) override;
	

private:
	TArray<EBlock> Blocks;
	
	void CreateQuad(FMask Mask, FIntVector AxisMask, FIntVector V1, FIntVector V2, FIntVector V3, FIntVector V4, int Width, int Height);
	int GetBlockIndex(int X, int Y, int Z) const;
	EBlock GetBlock(FIntVector Index) const;
	bool CompareMask(FMask M1, FMask M2) const;
	int GetTextureIndex(EBlock Block, FVector Normal) const;
};