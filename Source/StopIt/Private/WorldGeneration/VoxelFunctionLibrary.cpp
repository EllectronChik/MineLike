 // Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelFunctionLibrary.h"

#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"

FIntVector UVoxelFunctionLibrary::WorldToBlockPosition(const FVector& Position) {
	return FIntVector (Position) / 100;
}


FIntVector UVoxelFunctionLibrary::WorldToLocalBlockPosition(const FVector& Position, const int Size) {
	const auto ChunkPosition = WorldToChunkPosition(Position, Size);

	auto Result = WorldToBlockPosition(Position) - ChunkPosition * Size;

	if (ChunkPosition.X < 0) Result.X--;
	if (ChunkPosition.Y < 0) Result.Y--;
	if (ChunkPosition.Z < 0) Result.Z--;

	return  Result;
}


FIntVector UVoxelFunctionLibrary::WorldToChunkPosition(const FVector& Position, const int Size) {
	FIntVector Result;

	const int Factor = Size * 100;
	const auto IntPosition = FIntVector(Position);

	if (IntPosition.X < 0) Result.X = (int)(Position.X / Factor) - 1;
	else Result.X = (int)(Position.X / Factor);

	if (IntPosition.Y < 0) Result.Y = (int)(Position.Y / Factor) - 1;
	else Result.Y = (int)(Position.Y / Factor);

	if (IntPosition.Z < 0) Result.Z = (int)(Position.Z / Factor) - 1;
	else Result.Z = (int)(Position.Z / Factor);
	
	return Result;
}

 FIntVector UVoxelFunctionLibrary::GetBlockCenterPosition(const FVector& Position, const FVector& normal, int block_size) {
	FIntVector Result;

	Result = WorldToBlockPosition(Position);

	if (Position.X < 0) Result.X--;
	if (Position.Y < 0) Result.Y--;
	if (Position.Z < 0) Result.Z--;
	
	UKismetMathLibrary::Conv_IntVectorToVector(Result);

	Result.X += normal.X;
	Result.Y += normal.Y;
	Result.Z += normal.Z;

	Result.X = round(Result.X);
	Result.Y = round(Result.Y);
	Result.Z = round(Result.Z);

	Result.X *= block_size;
	Result.Y *= block_size;
	Result.Z *= block_size;

	Result.X += block_size / 2;
	Result.Y += block_size / 2;
	Result.Z += block_size / 2;

	Result.X = round(Result.X);
	Result.Y = round(Result.Y);
	Result.Z = round(Result.Z);
	
	return Result;
 }

 FVector UVoxelFunctionLibrary::MultiplyVector(FVector Position, float Num) {
	Position.X = Position.X * Num;
	Position.Y = Position.Y * Num;
	Position.Z = Position.Z * Num;

	return Position;
 }



FVector UVoxelFunctionLibrary::CoordinateToVector(float X, float Y, float Z) {
	FVector Position;
	Position.X = X;
	Position.Y = Y;
	Position.Z = Z;

	return Position;
}

FVector UVoxelFunctionLibrary::FloorVector(FVector Position) {
	Position.X = floor(Position.X);
	Position.Y = floor(Position.Y);
	Position.Z = floor(Position.Z);

	return Position;
 }

 bool UVoxelFunctionLibrary::IsObjectCollideWithPlayer(UCapsuleComponent* Capsule, FVector BlockCenter, int BlockSize) {
	UBoxComponent* BoxComp = NewObject<UBoxComponent>(Capsule -> GetOwner());
	BoxComp->RegisterComponent();
	BoxComp->SetWorldLocation(BlockCenter);
	BoxComp->SetBoxExtent(FVector(BlockSize / 2, BlockSize / 2, BlockSize / 2));

	bool bOverlap = Capsule -> IsOverlappingComponent(BoxComp);
	
	BoxComp->UnregisterComponent();
	BoxComp->DestroyComponent();
	
	if (bOverlap) {
		return true;
	} else {
		return false;
	}
 }

 

