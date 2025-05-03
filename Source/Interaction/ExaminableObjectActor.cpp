#include "ExaminableObjectActor.h"

// Sets default values for this component's properties
AExaminableObjectActor::AExaminableObjectActor()
{
}


// Called when the game starts
void AExaminableObjectActor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void AExaminableObjectActor::TickActor(float DeltaTime, enum ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	Super::TickActor(DeltaTime, TickType, ThisTickFunction);
}



