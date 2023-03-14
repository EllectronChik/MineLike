// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Util/Enums.h"
#include "CreateWorld.generated.h"

UCLASS()
class ACreateWorld : public AActor {
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category="Create World")
	TSubclassOf<AActor> ChunkType;

	UPROPERTY(EditAnywhere, Category = "Create World")
	int DrawDistance = 5;

	UPROPERTY(EditInstanceOnly, Category="Chunk")
	TObjectPtr<UMaterialInterface> Material;

	UPROPERTY(EditAnywhere, Category = "Create World")
	int Size = 32;

	UPROPERTY(EditInstanceOnly, Category="Height Map")
	EGenerationType GenerationType;

	UPROPERTY(EditInstanceOnly, Category="Height Map")
	float Frequency = 0.03f;
	
	// Sets default values for this actor's properties
	ACreateWorld();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	int ChunkCount;
	
	void Generate3DWorld();
	void Generate2DWorld();
};