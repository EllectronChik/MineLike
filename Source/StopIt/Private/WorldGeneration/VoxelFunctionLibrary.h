// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VoxelFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UVoxelFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category = "Voxel")
	static FIntVector WorldToBlockPosition(const FVector& Position);

	UFUNCTION(BlueprintPure, Category = "Voxel")
	static  FIntVector WorldToLocalBlockPosition(const FVector& Position, const int Size);

	UFUNCTION(BlueprintPure, Category = "Voxel")
	static FIntVector WorldToChunkPosition(const FVector& Position, const int Size);

	UFUNCTION(BlueprintPure, Category = "Voxel")
	static FIntVector GetBlockCenterPosition(const FVector& Position, const FVector& normal, int block_size);

	UFUNCTION(BlueprintPure, Category = "Math")
	static FVector MultiplyVector(FVector Position, float Num);

	UFUNCTION(BlueprintPure, Category = "Math")
	static FVector CoordinateToVector(float X, float Y, float Z);

	UFUNCTION(BlueprintPure, Category = "Math")
	static FVector FloorVector(FVector Position);

	UFUNCTION(BlueprintPure, Category = "Collision")
	static bool IsObjectCollideWithPlayer(UCapsuleComponent* Capsule, FVector BlockCenter, int BlockSize);
};
