# Yarr

Basic Transient and Permanent loading via the AssetManager

[YarrAssetManager.h](Source%2FYarr%2FCore%2FYarrAssetManager.h), [YarrAssetManager.cpp](Source%2FYarr%2FCore%2FYarrAssetManager.cpp)

Inline Pirate Spawn Actions

[PirateSpawnAction.h](Source%2FYarr%2FPirates%2FPirateSpawnAction.h)

### To Create an Asset Type
1. Create a new class that inherits from `UPrimaryDataAsset`

From `PrimaryDataAsset.h`
```cpp
/**
 * A DataAsset that implements GetPrimaryAssetId and has asset bundle support, which allows it to be manually loaded/unloaded from the AssetManager.
 * Instances of native subclasses can be created directly as Data Assets in the editor and will use the name of the native class as the PrimaryAssetType.
 * Or, blueprint subclasses can be created to add variables and then subclassed again by Data Only Blueprints that set those variables.
 * With blueprint subclasses, use Data Only Blueprints (and not Data Asset instances) to properly handle data inheritance and updating the parent class.
 */
```

2. Define your asset type in `DefaultGame.ini` under `[/Script/Engine.AssetManagerSettings]`
```ini
+PrimaryAssetTypesToScan=(PrimaryAssetType="PiratePartData",AssetBaseClass="/Script/Yarr.PiratePartData",bHasBlueprintClasses=False,bIsEditorOnly=True,Directories=((Path="/Game/Pirate/Data/Parts")),SpecificAssets=,Rules=(Priority=-1,ChunkId=-1,bApplyRecursively=True,CookRule=Unknown))
```

TIP: Use the editor to define your asset type in the config files and restart.

### How to Debug

```
showdebug yarr 
AssetManager.DumpLoadedAssets
AssetManager.UnloadPrimaryAssetsWithType PiratePartData
```

# Thanks to!
[Bugrimov Maxim](https://www.unrealengine.com/marketplace/en-US/profile/Bugrimov+Maksim) for this amazing [Pirate Asset Pack](https://www.unrealengine.com/marketplace/en-US/product/pirate-01)!
