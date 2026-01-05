# Sontags Keymap for Keebart Corne Choc Pro

A QWERTY layout with home-row mods and tap dance for a 3x5+3 split keyboard.

## Setup

The Keebart Corne Choc Pro is not part of the main QMK repository. This userspace contains the full keyboard definition, not just the keymap. You need to create a symlink in your QMK installation:

```bash
# From your QMK firmware directory
ln -s /path/to/qmk_userspace/keyboards/keebart ~/qmk_firmware/keyboards/keebart
```

Then configure the userspace overlay:

```bash
qmk config user.overlay_dir="/path/to/qmk_userspace"
```

## Build Commands

```bash
# Compile
qmk compile -kb keebart/corne_choc_pro/mini -km sontags

# Or using make
make keebart/corne_choc_pro/mini:sontags
```

## Layers

### Layer 0: Base (QWERTY)

```
┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
│  Q  │  W  │  E  │  R  │  T  │     │      │     │  Y  │  U  │  I  │  O  │  P  │
├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
│ A*  │ S*  │ D*  │ F*  │G/L4 │     │      │     │H/L4 │ J*  │ K*  │ L*  │ ;*  │
├─────┼─────┼─────┼─────┼─────┼─────┘      └─────┼─────┼─────┼─────┼─────┼─────┤
│  Z  │  X  │  C  │  V  │  B  │                  │  N  │  M  │  ,  │  .  │  /  │
└─────┴─────┴─────┴─────┴─────┘                  └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┬─────┬─────┐      ┌─────┬─────┬─────┐
                  │     │ L1  │Space│      │Enter│ L2  │     │
                  └─────┴─────┴─────┘      └─────┴─────┴─────┘
```

*Home-row mods (hold for modifier, tap for letter):*

| Key | Tap | Hold |
|-----|-----|------|
| A | a | Shift |
| S | s | Alt |
| D | d | Ctrl |
| F | f | GUI |
| J | j | GUI |
| K | k | Ctrl |
| L | l | Alt |
| ; | ; | Shift |

- `G` and `H`: Tap for letter, hold for Layer 4

**Tap Dance (Space key):**
- Single tap: Space
- Single hold: Activate Layer 3 (Mouse)
- Double hold: Hold Space (for repeating)

### Layer 0: Base (DVORAK Visualization)

For users familiar with DVORAK, this is what you type:

```
┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
│  '  │  ,  │  .  │  P  │  Y  │     │      │     │  F  │  G  │  C  │  R  │  L  │
├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
│ A*  │ O*  │ E*  │ U*  │I/L4 │     │      │     │D/L4 │ H*  │ T*  │ N*  │ S*  │
├─────┼─────┼─────┼─────┼─────┼─────┘      └─────┼─────┼─────┼─────┼─────┼─────┤
│  ;  │  Q  │  J  │  K  │  X  │                  │  B  │  M  │  W  │  V  │  Z  │
└─────┴─────┴─────┴─────┴─────┘                  └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┬─────┬─────┐      ┌─────┬─────┬─────┐
                  │     │ L1  │Space│      │Enter│ L2  │     │
                  └─────┴─────┴─────┘      └─────┴─────┴─────┘
```

### Layer 1: Function Keys & Numbers

```
┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ F1  │ F2  │ F3  │ F4  │ F5  │     │      │     │  1  │  2  │  3  │  4  │  5  │
├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
│ F6  │ F7  │ F8  │ F9  │ F10 │     │      │     │  6  │  7  │  8  │  9  │  0  │
├─────┼─────┼─────┼─────┼─────┼─────┘      └─────┼─────┼─────┼─────┼─────┼─────┤
│ F11 │ F12 │ F13 │ F14 │ F15 │                  │  +  │  -  │  *  │  /  │  ]  │
└─────┴─────┴─────┴─────┴─────┘                  └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┬─────┬─────┐      ┌─────┬─────┬─────┐
                  │     │ [*] │     │      │     │     │     │
                  └─────┴─────┴─────┘      └─────┴─────┴─────┘
```

### Layer 2: Symbols & Navigation

```
┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
│  !  │  @  │  #  │  $  │     │     │      │     │     │Home │PgDn │PgUp │ End │
├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
│  ^  │  &  │  *  │  %  │     │     │      │     │     │  ←  │  ↓  │  ↑  │  →  │
├─────┼─────┼─────┼─────┼─────┼─────┘      └─────┼─────┼─────┼─────┼─────┼─────┤
│  ~  │  |  │  \  │  `  │     │                  │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┘                  └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┬─────┬─────┐      ┌─────┬─────┬─────┐
                  │     │     │     │      │     │ [*] │     │
                  └─────┴─────┴─────┘      └─────┴─────┴─────┘
```

### Layer 3: Mouse Keys

Activated by holding the tap-dance Space key.

```
┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
│     │     │     │     │     │     │      │     │     │Scr← │Scr↓ │Scr↑ │Scr→ │
├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
│Btn4 │Btn3 │Btn2 │Btn1 │     │     │      │     │     │Ms ← │Ms ↓ │Ms ↑ │Ms → │
├─────┼─────┼─────┼─────┼─────┼─────┘      └─────┼─────┼─────┼─────┼─────┼─────┤
│     │     │     │     │     │                  │     │     │     │     │     │
└─────┴─────┴─────┴─────┴─────┘                  └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┬─────┬─────┐      ┌─────┬─────┬─────┐
                  │     │     │[Spc]│      │     │     │     │
                  └─────┴─────┴─────┘      └─────┴─────┴─────┘
```

### Layer 4: Additional Symbols

Activated by holding `G` or `H` on the base layer.

```
┌─────┬─────┬─────┬─────┬─────┬─────┐      ┌─────┬─────┬─────┬─────┬─────┬─────┐
│ Esc │  -  │  _  │  (  │ S-W │     │      │     │ S-E │  )  │  +  │  =  │Bksp │
├─────┼─────┼─────┼─────┼─────┼─────┤      ├─────┼─────┼─────┼─────┼─────┼─────┤
│ Tab │     │     │     │ [*] │     │      │     │ [*] │     │     │     │     │
├─────┼─────┼─────┼─────┼─────┼─────┘      └─────┼─────┼─────┼─────┼─────┼─────┤
│  ~  │  '  │  "  │  /  │     │                  │     │  \  │     │  {  │  |  │
└─────┴─────┴─────┴─────┴─────┘                  └─────┴─────┴─────┴─────┴─────┘
                  ┌─────┬─────┬─────┐      ┌─────┬─────┬─────┐
                  │     │     │     │      │     │     │     │
                  └─────┴─────┴─────┘      └─────┴─────┴─────┘
```

*Note: `[*]` indicates the layer activation key*

## Configuration

- **Tapping term**: 200ms
- **Quick tap term**: 200ms
- **Permissive hold**: Enabled
- **Tap dance**: Enabled
- **LTO**: Enabled (smaller firmware size)
