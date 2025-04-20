# so_long

## 🎮 Description

**so_long** is a 42 school project that consists of creating a small 2D game using **MiniLibX**, a simple graphical library provided by the school.

The goal is to practice file parsing, graphical rendering, data validation, and game logic while respecting strict programming constraints.

---

## 🧩 Objectives

- Read and parse a map file in `.ber` format.
- Render the map dynamically using 2D sprites.
- Allow the player to move with keyboard inputs.
- Manage interactions (collecting items, reaching the exit).
- Count and display the number of movements.
- Exit the game properly when the player wins or closes the window.

---

## 🚀 Features

### ✅ Game Engine

- 2D map rendering with walls, floor, collectibles, exit, and player.
- Player movement using `W`/`Z`, `A`/`Q`, `S`, `D` (or arrow keys).
- Movement count displayed in the terminal.
- Clean exit when closing the window or pressing `ESC`.

### 🧠 Parsing & Validation

- **Reads and validates the game map** :
  - Must be rectangular.
  - Surrounded by walls.
  - Must contain at least one exit, one player, and one collectible.
  - Map must be solvable (validated with a pathfinding algorithm).

### 🎨 Graphics

- Uses **MiniLibX** for graphical rendering.
- Custom sprites for each type of map element.

---

## 📁 Map Format

The map file must have a `.ber` extension and follow this structure :

- `1` : Wall
- `0` : Floor
- `P` : Player start
- `C` : Collectible
- `E` : Exit

Bonus with :

- `X` : Exit

---

## 🛠️ Compilation

```bash
make
./so_long map/map0X.ber
