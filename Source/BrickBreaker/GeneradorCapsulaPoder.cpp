// Fill out your copyright notice in the Description page of Project Settings.


#include "GeneradorCapsulaPoder.h"


//ACapsula* AGeneradorCapsulaPoder::MakeCapsule(FString CapsuleTypeName)
//{
//
//	float RandomSpawnX = FMath::RandRange(-650, 300);	// Un punto en el eje X
//	const FVector SpawnLocation = FVector(RandomSpawnX, -360.f, 0.f);	// punto de creacion de la capsula
//	const FRotator Rotation = FRotator(0.f, 0.f, 0.f);	// rotacioi de la capsula
//
//	return nullptr;
//
//}

bool AGeneradorCapsulaPoder::FabricarCapsula(FString NombreTipoCapsula)
{
	float LuagarAparicion = FMath::RandRange(-300, 600);
	const FVector SpawnLocation = FVector(LuagarAparicion, -360.f, 0.f);
	const FRotator Rotation = FRotator(0.f, 0.f, 0.f);

	if (NombreTipoCapsula.Equals("Energia1")) {

		GetWorld()->SpawnActor<AGeneradorCapsulaPoder>(SpawnLocation, Rotation);
		return true;
	}

	/*if (NombreTipoCapsula.Equals("Vida1")) {
		GetWorld()->SpawnActor<APaFM_CApsulaVida1>(SpawnLocation, Rotation);
		return true;
	}*/

	return false;
}