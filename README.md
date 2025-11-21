# Mini-maze game (C + SDL3)

Mini maze adalah proyek kecil yang saya buat untuk belajar dan memahami:
- Struktur program C yang modular
- Sistem logging (debug, info, dan error)
- Render 2D menggunakan library SDL3
- Algoritma Depth-First Search (DFS) untuk menggenerasi maze
- Game loop 60 FPS
- Pemrosesan input dan rendering berbasis tile grid

Game ini secara otomatis menghasilkan maze acak, baik saat game dimulai maupun ketika player mencapai titik akhir.
Player (warna hijau) harus mencapai tujuan biru, dan posisi spawn ditandai merah.
Warna putih adalah dinding maze.
Skema warna tidak memiliki makna khusus—hanya untuk memudahkan visualisasi.

## Fitur game:

- Maze generator berbasis **DFS recursive backtracking**
- Render berbasis **grid & tile 32×32**
- Player dapat bergerak (bug teknis player bisa bergerak lebih cepat ketika berpindah arah)
- Maze yang berubah ketika tujuannya telah dicapai
- Sistem logging ('LOG_DEBUG', 'LOG_INFO', 'LOG_ERROR')
- Game loop yang cukup stabil (target 60 FPS)
- Struktur kode yang rapih dan modular ('src/', 'include/')


---

## Algorithm: DFS Maze Generation

Maze dibuat menggunakan algoritma **Depth-First Search Recursive Backtracking**:

1. Pilih sel awal (harus koordinat ganjil).
2. Tandai sebagai jalan.
3. Acak urutan arah.
4. Lompati 2 langkah ke sel berikutnya.
5. Jika target belum dikunjungi, buka dinding dan lanjutkan DFS.
6. Rekursi sampai semua sel dikunjungi.

Algoritma ini menjamin maze selalu solvable (tidak ada ruang tertutup).

---

## Requirements

- SDL3
- GCC / Clang
- Make
- MSYS2 (untuk Windows)

## Instalasi (Linux)

Install SDL3 dev:

```bash
sudo apt install libsdl3-dev
```

## Instalasi (Windows – MSYS2 + MINGW64 + SDL3)

### 1. Install MSYS2

Download di situs resmi:

```arduino
https://ww.msys2.org
```

Setelah selesai, buka terminal MSYS2 MSYS dan update sistem:

```bash
pacman -Syu
```

Tutup terminal, buka lagi dan ulangi:

```bash
pacman -Su
```

### 2. Install compiler MINGW64

Jalankan:

```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make
```

### 3. Install SDL3 (Windows)

Jalankan:

```bash
pacman -S mingw-w64-x86_64-SDL3
```

### 4. Gunakan shell yang benar

PENTING: gunakan MINGW64 Shell untuk build.

(Biasanya berada di: MSYS2 MinGW 64-bit)

atau konfigurasi edit path environment variabel

## Build & Run

### Build

```bash
make
```

### Run

Linux:

```bash
./build/myApp
```

Windows

```bash
Start build/myApp
```

## Struktur Proyek

```csharp
maze-game/
│
├── src/
│   ├── main.c
│   ├── init.c
│   ├── game.c
│   ├── render.c
│   └── maze.c
│
├── include/
│   ├── init.h
│   ├── render.h
│   ├── maze.h
│   └── debug.h
│
├── build/          # output binary dan .o
├── assets/         # screenshot, sprite, dll (opsional)
├── makefile
└── README.md
```

## Debug Logging

gunakan flag:

```diff
-DENABLE_DEBUG
```

Contoh output debug:

```pgsql
[DEBUG] init.c:34:InitializeSDLResources(): Initialize SDL resources successful
[INFO] maze.c:16:InitGrid(): Initialized all grid cells to 1
```

## Contributing

Pull request diterima!
Proyek ini dibuat untuk belajar, jadi kontribusi berupa saran atau perbaikan sangat dihargai.

## Author

Nama: StormCLs
Mahasiswa Teknik Informatika – Universitas Al Khairiyah
Tujuan proyek: latihan logika, algoritma DFS, dan pengembangan game 2D sederhana.