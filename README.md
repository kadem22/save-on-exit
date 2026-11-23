# Save On Level Exit

Saves your GD data whenever you exit a level (pause menu exit, or menu button on the level complete screen). No periodic saving, so no mid-run freezes.

## Build
1. Install the Geode CLI and SDK: https://docs.geode-sdk.org/getting-started/
2. In this folder run:
   geode build
3. The resulting `.geode` file goes in your Geometry Dash `geode/mods` folder (or `geode package install`).

## Notes
- If the build complains about the "geode" version in mod.json, set it to the Geode version you have installed (`geode sdk version`).
- The "gd" field targets 2.2081. Change it if your GD version string differs.
