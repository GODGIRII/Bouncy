
# 🌍 Bouncy Ball Gravity Simulator (SDL3 + C)

Simulate a bouncy ball under different planetary gravities using SDL3 and C.

Choose a planet from our solar system and watch how gravity affects the ball’s motion — from the light bounce of the Moon to the crushing pull of Jupiter.

---

## 🎮 Features

- Realistic gravity simulation for 9 planets
- Frame-rate independent physics (`deltaTime`)
- Circle rendering via SDL3
- Terminal-based planet selection menu
- Clean and simple structure using only C and SDL

---

## 🛠️ How to Build

### 🔧 Requirements

- Linux (tested on Arch)
- SDL3 (installed via your system or from source)
- `gcc` compiler

### 🧪 Compile

```bash
gcc bouncy.c -o bouncy $(pkg-config --cflags --libs sdl3)
```

This will produce an executable called `bouncy`.

---

## 🧾 How to Use

### 📦 Launch from Terminal

```bash
./bouncy
```

You’ll be prompted to select a planet. The simulation will launch in a GUI window.

---

### 🖱️ Launch via GUI (Thunar / File Manager)

You can make this feel like a full app with GUI launch support:

#### 1. Compile your binary

```bash
gcc bouncy.c -o bouncy $(pkg-config --cflags --libs sdl3)
```

#### 2. Move the binary to a user apps folder

```bash
mkdir -p ~/Applications/BouncyBall
mv bouncy ~/Applications/BouncyBall/
chmod +x ~/Applications/BouncyBall/bouncy
```

#### 3. Create a `.desktop` file to make it launchable

```bash
nano ~/.local/share/applications/bouncy.desktop
```

Paste this:

```ini
[Desktop Entry]
Type=Application
Name=Bouncy Ball
Exec=/home/YOUR_USERNAME/Applications/BouncyBall/bouncy
Icon=applications-games
Terminal=false
Categories=Game;
```

> Replace `/home/YOUR_USERNAME` with your actual path.

#### 4. Make it executable

```bash
chmod +x ~/.local/share/applications/bouncy.desktop
```

Now it will appear in your **app launcher**, and you can launch it by double-clicking from **Thunar or your menu**.

---

## 🧠 How It Works

- Ball position and velocity are updated each frame using delta time.
- Gravity is planet-dependent, based on user choice.
- Ball bounces off edges using simple collision logic.

---

## 📂 Folder Structure

```
.
├── bouncy.c             # main source code
├── README.md            
├── icon.png             # optional: app icon
└── bouncy.desktop       # optional: desktop entry
```

---

## 🛤️ Roadmap

- [ ] Mouse click to spawn ball
- [ ] Add textures instead of solid color
- [ ] Sound effects on bounce
- [ ] Real UI menu for planet selection (using SDL)
- [ ] Config file for saving preferences

---

## 🧑‍💻 Author

Made with C and GodGiri

---

## 📜 License

MIT — free to use, modify, and share.
