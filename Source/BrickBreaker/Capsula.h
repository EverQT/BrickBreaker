// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/CapsuleComponent.h"
#include "Capsula.generated.h"

UCLASS()
class BRICKBREAKER_API ACapsula : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACapsula();


	// componente root
	UPROPERTY(EditAnywhere)
		USceneComponent* DefaulSceneRoot;

	// Malla de la clase Mi capsula
	UPROPERTY(EditAnywhere, Category = "Componentes Capsula")
		class UStaticMeshComponent* CapsuleMesh;
	UPROPERTY(EditAnywhere, Category = "Componentes Capsula")
		class UCapsuleComponent* CapsuleCollision; // para colisiones

	// nombre de la capsula
	FString NameCapsula;

	// velocidad de la capsula
	float VelocityCapsula;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// otro metodo
	virtual void Generar();
	void Destruir();

	FORCEINLINE FString GetNombre() const { return NameCapsula; }

};
