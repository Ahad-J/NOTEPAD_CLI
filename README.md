
<h1 align="center">📝 Console Notepad Editor</h1>
<p align="center">
  <i>A minimalist text editor built in C++ using a custom doubly-linked list structure.</i>
</p>

---

## ✨ Features
<ul>
  <li>📄 Edit existing or new text files directly from the console</li>
  <li>⬅️ ➡️ Cursor movement using arrow keys</li>
  <li>🔤 Character-by-character input handling</li>
  <li>🔙 Backspace support for deletion</li>
  <li>💾 Realtime file save after every keystroke</li>
</ul>

---

## ⚙️ Technical Details

<table>
  <tr>
    <td><b>💻 Language</b></td>
    <td>C++</td>
  </tr>
  <tr>
    <td><b>📦 Files</b></td>
    <td>Single file with main code (no external dependencies except <code>Windows.h</code>)</td>
  </tr>
  <tr>
    <td><b>📁 Data Structure</b></td>
    <td>Custom Doubly Linked List with cursor tracking</td>
  </tr>
</table>

---

## 🕹 Controls

| Key         | Action                   |
|-------------|---------------------------|
| Characters  | Insert at cursor position |
| Backspace   | Delete character before cursor |
| ← / → Arrow | Move cursor left/right    |
| Enter       | Insert newline             |
| Esc         | Exit editor                |

---

## 🚀 How to Run

### 🛠 Prerequisites:
- A C++ compiler (e.g., g++, MSVC)
- Windows OS (due to use of `Windows.h` and `_getch()`)

### 📦 Compilation Example (g++):
```bash
g++ notepad.cpp -o notepad
```

### ▶️ Usage:
1. Run the compiled file.
2. Enter a filename (with or without `.txt`).
3. Start typing! Your content will be saved live.
4. Press `Esc` to exit.

---

## 🧠 Core Logic

- `List<char>`: Custom template class for linked list text storage.
- Cursor tracking and rendering are handled internally.
- Uses `fstream` for reading/writing file content.
- `display()`: Clears and redraws text with `|` as a cursor marker.

---

## 📄 License

🆓 This project is free for educational use.  
📢 Attribution is welcome but not required.

<p align="center"><b>🔧 Built with C++ for simplicity & learning.</b></p>
