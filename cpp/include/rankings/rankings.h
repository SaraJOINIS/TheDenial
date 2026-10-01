#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SaveRanking.generated.h"

/**
 * Classe de gestion des scores joueurs via JSON
 */
UCLASS()
class YOURPROJECT_API USaveRanking : public UObject
{
    GENERATED_BODY()

public:
    USaveRanking();

    /**
     * Ajoute ou met à jour le score d’un joueur dans le fichier JSON
     * @param PlayerName - Nom du joueur
     * @param NewScore - Nouveau score à enregistrer
     * @return true si succès, false sinon
     */
    bool AddOrUpdatePlayerScore(const FString &PlayerName, int32 NewScore);
};
