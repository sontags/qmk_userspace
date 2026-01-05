# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a QMK userspace repository containing custom keymaps for mechanical keyboards. It uses the QMK external userspace feature to maintain keymaps separately from the main QMK firmware repository.

## Build Commands

```bash
# Compile a specific keyboard/keymap
qmk compile -kb <keyboard> -km <keymap>
# Example: qmk compile -kb keebart/corne_choc_pro/mini -km sontags

# Alternative make syntax
make <keyboard>:<keymap>
# Example: make keebart/corne_choc_pro/mini:sontags

# Compile all configured build targets at once
qmk userspace-compile
```

## Setup

Before building, configure the userspace overlay:
```bash
qmk config user.overlay_dir="$(realpath .)"
```

## Build Targets

Current keyboards defined in `qmk.json`:
- `keebart/corne_choc_pro/mini:sontags` - Keebart Corne Choc Pro (split keyboard)
- `ploopyco/trackball_nano/rev1_001:sontags` - Ploopy Nano trackball with wiggle-to-scroll toggle
- `lily58/rev1:sontags` - Lily58 split keyboard

## Architecture

### Keymap Structure
- `keyboards/<manufacturer>/<model>/keymaps/sontags/` - Keymap files
  - `keymap.c` - Key layout definitions
  - `config.h` - Keyboard-specific configuration overrides
  - `rules.mk` - Feature flags (RGB, audio, etc.)

### Layer Convention
All keymaps use 5 layers:
- Layer 0: Base QWERTY with home-row mods (Shift/Alt/Ctrl/GUI on ASDF and JKL;)
- Layer 1: Function keys (F1-F15) and numbers
- Layer 2: Symbols and navigation (Home/End/PgUp/PgDn/arrows)
- Layer 3: Mouse keys (buttons, scroll, movement)
- Layer 4: Additional symbols (brackets, quotes, backspace, escape)

### Ploopy Trackball Custom Code
The trackball keymap (`keyboards/ploopyco/trackball_nano/rev1_001/keymaps/sontags/keymap.c`) includes custom wiggle detection that toggles scroll mode when the ball is shaken horizontally.

## CI/CD

GitHub Actions automatically builds firmware on push and publishes to Releases.
