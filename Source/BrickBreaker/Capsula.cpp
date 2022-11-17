// Fill out your copyright notice in the Description page of Project Settings.


#include "Capsula.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACapsula::ACapsula()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Llamano al componente ruta
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Establecemos el mesh que llevara la capsula 
	static ConstructorHelpers::FObjectFinder<UStaticMesh> AssetCapsula(TEXT("StaticMesh'/Game/Meshes/Weapon.Weapon'"));
	CapsuleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Capsula"));
	CapsuleMesh->SetStaticMesh(AssetCapsula.Object);

	// configurando el campo de colision de este actor
	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collision Enemy"));
	CapsuleCollision->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	CapsuleCollision->SetCapsuleHalfHeight(35.0f);
	CapsuleCollision->SetCapsuleRadius(17.0f);

	// atachando al comoponente root
	CapsuleMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CapsuleCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);


}

// Called when the game starts or when spawned
void ACapsula::BeginPlay()
{
	Super::BeginPlay();

	// velocidad predeterminada
	VelocityCapsula = 40.f;

}

// Called every frame
void ACapsula::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector MoveDirection = FVector(0.f, 1.f, 0.f);		// direccion del movimiento
	const FVector Movement = MoveDirection * VelocityCapsula * DeltaTime;	// la velocidad en la que se va mover

	if (Movement.SizeSquared() > 0.0f) {
		const FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f); // la rotacion de la capsula

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}

	// destruir la capsula si sobrepasa el punto 390 en el eje de las Y
	if (this->GetActorLocation().Y > 390.f) {
		this->Destroy();
	}

}

// ------------------
void ACapsula::Generar()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Capsula Generada")));
}

void ACapsula::Destruir()
{
	if (CapsuleMesh) {
		this->Destroy();
	}
}
