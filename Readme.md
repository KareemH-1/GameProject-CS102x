# CS102x Game Project &nbsp; <img alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?logo=c%2B%2B&logoColor=white&style=for-the-badge" height="28"/>

<p align="center">
  <img src="ScreenShots/Menu.png" alt="Game Menu" width="400"/><br>
  <b>A Feature-Packed Terminal Platformer Adventure!</b>
</p>

<p align="center">
  <a href="#screenshots"><img src="https://img.shields.io/badge/Demo-Screenshots-blue?style=flat-square"></a>
  <a href="#how-to-build-and-run"><img src="https://img.shields.io/badge/Build-Passing-brightgreen?style=flat-square"></a>
  <a href="#features"><img src="https://img.shields.io/badge/Features-✓-orange?style=flat-square"></a>
  <a href="#credits"><img src="https://img.shields.io/badge/Credits-Team-lightgrey?style=flat-square"></a>
</p>

---

## 🚀 About the Project

**CS102x Game Project** is a challenging, large-scale, single-player platformer, fully playable in your terminal and crafted entirely in C++. You'll jump, climb, shoot, and strategize your way through a massive ASCII world packed with hazards, secrets, and epic boss battles.

> **"A nostalgic adventure where code meets creativity, and every frame is hand-drawn with ASCII art."**

---

## 🎮 Gameplay Overview

- **Explore** a vast, scrollable ASCII map filled with platforms, elevators, ladders, traps, and secrets.
- **Collect** 10 coins to unlock the mysterious teleporter and gain access to the final boss area.
- **Upgrade** by discovering hidden power-ups like hearts (for health) and a powerful assault rifle.
- **Fight** waves of unique enemies, from birds to blobs, skeletons, and minibosses.
- **Survive** perilous obstacles: spikes, moving platforms, falling crystals, and devilish traps.
- **Defeat** the mighty boss (but beware its minions and deadly laser attacks!) to achieve ultimate victory.

---

## 🖼️ Screenshots

<table>
  <tr>
    <td align="center"><b>Menu</b><br><img src="ScreenShots/Menu.png" width="280"></td>
    <td align="center"><b>Game Start</b><br><img src="ScreenShots/Start.png" width="280"></td>
    <td align="center"><b>Moving Platform</b><br><img src="ScreenShots/Moving_Platform.png" width="280"></td>
  </tr>
  <tr>
    <td align="center"><b>Fighting the Devil</b><br><img src="ScreenShots/Devil.png" width="280"></td>
    <td align="center"><b>Lazer Gun in Action</b><br><img src="ScreenShots/Lazer.png" width="280"></td>
    <td align="center"><b>Epic Final Boss</b><br><img src="ScreenShots/FinalBoss.png" width="280"></td>
  </tr>
</table>

---

## 🕹️ Controls

| Key         | Action                                  |
|-------------|-----------------------------------------|
| **W**/Space | Jump / Climb Up                         |
| **A**       | Move Left                               |
| **D**       | Move Right                              |
| **S**       | Climb Down                              |
| **F**       | Shoot                                   |
| **R**       | Reload                                  |
| **T**       | Switch Weapons                          |
| **E**       | Interact (teleporter, button, etc.)     |

---

## ✨ Features

- **ASCII Art Graphics** – Every sprite and animation is painstakingly crafted using only terminal characters.
- **Physics & Platforming** – Realistic jumping, falling, climbing, and moving platforms.
- **Multiple Weapons** – Start with a pistol and a lazer, then unlock the assault rifle for rapid-fire carnage.
- **Diverse Enemies** – Each with unique patterns: birds drop eggs, devils shoot fireballs, bosses unleash lasers!
- **Dynamic Map** – Massive world with smooth scrolling, secret ladders, elevators, and interactive objects.
- **HUD & Stats** – Always see your health, coins, equipped weapon, and ammo.
- **Endgame Sequence** – Defeat two skeleton minions before you can even damage the boss.
- **Replayable** – Each run is a test of platforming and combat skill.

---

## 🧠 Analysis & Design Highlights

- **Pure C++** – No graphics libraries, no dependencies; just logic, arrays, and ASCII.
- **Game Loop** – Custom handling for player input, enemy AI, and real-time rendering using efficient in-place terminal redraws.
- **Stateful Entities** – All objects (player, enemies, coins, hearts, elevators) are structured for easy extension.
- **Collision System** – Custom hitboxes and detection for both player and enemy interactions.
- **Scalability** – The game world is much larger than the visible screen, with active scrolling and "camera" logic.
- **User-Friendly** – Main menu, instructions, credits, and win/lose screens for a polished arcade feel.

---

## 🏗️ How to Build and Run

### Requirements

- **C++ Compiler:** Any modern compiler supporting C++11 or later (e.g., g++, clang, MSVC)
- **Operating System:** Windows (recommended for `<conio.h>` support); Linux requires minor code tweaks for input.
- **Terminal:** At least 80x24 characters.

### Build (Windows Example)

```sh
g++ -o cs102x_game Game.cpp
```

### Run

```sh
./cs102x_game
```

> **Note:**  
> On Linux/Mac, replace `<conio.h>`, `_getch()`, and `_kbhit()` with equivalents (see [this resource](https://stackoverflow.com/questions/7469139/what-is-equivalent-to-getch-getche-in-linux)).

---

## 🌟 Why You'll Love This Game

- **Nostalgia:** Classic platformer mechanics meets old-school ASCII charm.
- **Challenge:** The difficulty ramps up—timing, reflexes, and strategy all matter.
- **Creativity:** See what's possible with just C++ and your imagination.
- **Great for Learning:** Explore code organization, state management, and game loops in a pure C++ environment.

---

## 👥 Credits

Game developed by:

- [Kareem Ahmed Taha](https://github.com/KareemH-1)
- [Mazen Mahmoud Gamal](https://github.com/MazenMDev)
- [Ahmed Emad Mohammed](https://github.com/AhmedEmad375)

---

<div align="center">
  <b>Enjoy exploring, fighting, and winning in the world of ASCII!</b><br>
  <i>We welcome your feedback, stars, and contributions!</i>
</div>