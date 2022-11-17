// Copyright Epic Games, Inc. All Rights Reserved.


#include "BrickBreakerGameModeBase.h"
#include "GeneradorCapsulaPoder.h"
#include "GeneradorCapsulaDano.h"

ABrickBreakerGameModeBase::ABrickBreakerGameModeBase()
{

	PrimaryActorTick.bCanEverTick = true;

	// inicializando los valores a las propiedades que usara la fabrica de capsula
	StartSpawnCapsule = 0.0;
	TopSpawnCapsule = 5.f;


}

void ABrickBreakerGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	limiteCreate = 2;

	//singelton permite instanciar objetos clases, un paddle no crear 10+ Brick a patir de un solo Brick
	
	for (int i = 0; i <= 4; i++)
	{
		int c = 0;
		c = c + i;
		if (c <= limiteCreate - 1) {
			APaddle* SpawnedPaddle = GetWorld()->SpawnActor<APaddle>(APaddle::StaticClass());
			Paddle = SpawnedPaddle;
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s has been created"), *Paddle->GetName()));
		}
	}

	/*APaddle* SpawnedPaddle = GetWorld()->SpawnActor<APaddle>(APaddle::StaticClass());
	Paddle = SpawnedPaddle;
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("%s has been created"), *Paddle->GetName()));*/

	ABrickBreakerGameModeBase* gm = Cast<ABrickBreakerGameModeBase>(GetWorld()->GetAuthGameMode());
	if (gm) {

		// creamos objeto
		ACapsula* nuevoObjeto = NewObject<ACapsula>((UObject*)GetTransientPackage(), ACapsula::StaticClass());
		Capsula = nuevoObjeto;
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Blue, FString::Printf(TEXT("%s Ha sido creado"), *Capsula->GetName()));
	}

	for (int x = 0; x <= 3 - 1; x++) {
		AGeneradorCapsula* GeneradorCapsulas;
		GeneradorCapsulas = GetWorld()->SpawnActor<AGeneradorCapsulaPoder>(AGeneradorCapsulaPoder::StaticClass());
		GeneradorCapsulas->ConstruirCapsula("Energia1");
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Capsula Creada")));
	}

	for (int y = 0; y <= 3 - 1; y++) {
		AGeneradorCapsula* GeneradorCapsulas;
		GeneradorCapsulas = GetWorld()->SpawnActor<AGeneradorCapsulaDano>(AGeneradorCapsulaDano::StaticClass());
		GeneradorCapsulas->ConstruirCapsula2("Energia1");
		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Capsula Creada")));
	}

}

void ABrickBreakerGameModeBase::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("Some warning message"), &DeltaTime);

	// Sistema para aparicion de las capsulas
	//StartSpawnCapsule += DeltaTime;
	//if (StartSpawnCapsule >= TopSpawnCapsule)
	//{
	//	StartSpawnCapsule = 0.f;
	//	float AppearanceChance = FMath::RandRange(0, 150);	// probabilidad de aparicion para cada capsula
	//	// declarando la fabrica de capsula
	//	AGeneradorCapsula* CapsuleGenerator;
	//	if (AppearanceChance <= 20.f) {		// para municion de la bala 1 del jugador
	//		CapsuleGenerator = GetWorld()->SpawnActor<AGeneradorCapsulaPoder>(AGeneradorCapsulaPoder::StaticClass());
	//		CapsuleGenerator->getCapsule("BulletAmmunition1");
	//	}
	//}

	// creacion de capsulas con el patron factory method
	
	//InicioSpawn += DeltaTime;
	//if (InicioSpawn >= TopSpawn)
	//{
	//	InicioSpawn = 0.f;
	//	float ProbalidadAparicion = FMath::RandRange(0, 100);
	//	AGeneradorCapsula* GeneradorCapsulas;

	//	if (ProbalidadAparicion <= 1.f) {
	//		GeneradorCapsulas = GetWorld()->SpawnActor<AGeneradorCapsulaPoder>(AGeneradorCapsulaPoder::StaticClass());
	//		GeneradorCapsulas->ConstruirCapsula("Energia1");
	//		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Capsula Creada")));
	//	}
	//}

	//InicioSpawn += DeltaTime;
	//if (InicioSpawn >= TopSpawn)
	//{
	//	InicioSpawn = 0.f;
	//	float ProbalidadAparicion = FMath::RandRange(0, 100);
	//	AGeneradorCapsula* GeneradorCapsulas;

	//	if (ProbalidadAparicion <= 1.f) {
	//		GeneradorCapsulas = GetWorld()->SpawnActor<AGeneradorCapsulaDano>(AGeneradorCapsulaDano::StaticClass());
	//		GeneradorCapsulas->ConstruirCapsula2("Energia1");
	//		//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, FString::Printf(TEXT("Capsula Creada")));
	//	}
	//}
}
