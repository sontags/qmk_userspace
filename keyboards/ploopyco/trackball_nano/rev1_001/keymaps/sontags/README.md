# Sontags Keymap for Ploopy Nano Trackball

Custom firmware for the Ploopy Nano trackball with wiggle-to-scroll toggle functionality.

## Build Commands

```bash
# Compile
qmk compile -kb ploopyco/trackball_nano/rev1_001 -km sontags

# Or using make
make ploopyco/trackball_nano/rev1_001:sontags
```

Configure the userspace overlay if not already done:

```bash
qmk config user.overlay_dir="/path/to/qmk_userspace"
```

## Features

### Wiggle-to-Scroll Toggle

Quickly shake the trackball horizontally (left-right-left-right) to toggle between cursor mode and scroll mode. This allows switching modes without pressing any buttons.

The wiggle detection code is based on [pandrr/wiggleball](https://github.com/pandrr/wiggleball).

**Detection parameters:**
- Requires 4+ direction changes within 150ms between shakes
- Horizontal movement only (minimal vertical movement)
- 250ms cooldown after toggling to prevent accidental re-triggers

### Scroll Mode

When scroll mode is active:
- Trackball movement is converted to scroll wheel input
- Accumulated movement threshold of 150 units before registering a scroll tick
- Horizontal and vertical scrolling supported
- Smooth, controlled scroll speed

### Button Toggle

Clicking the trackball button also toggles scroll mode on/off as an alternative to the wiggle gesture.

## Usage

1. **Normal cursor mode**: Move the trackball to move the mouse cursor
2. **Toggle to scroll mode**: Either:
   - Wiggle the ball horizontally (shake left-right quickly), or
   - Click the trackball button
3. **Scroll**: Roll the ball to scroll (up/down and left/right)
4. **Toggle back to cursor mode**: Wiggle again or click the button
