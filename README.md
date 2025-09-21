# Face Blur GUI Application

This project is a graphical user interface (GUI) application that allows users to open an image, detect faces within it, select faces to blur, and save the modified image without overwriting the original file.

## Features

- Open an image file from the local filesystem.
- Automatically detect faces in the image.
- Select specific faces to apply a blur effect.
- Save the modified image with a new filename to prevent overwriting the original.

## Project Structure

```
face-blur-gui-app
├── src
│   ├── main.ts               # Entry point of the application
│   ├── gui
│   │   └── index.ts          # GUI management and user interactions
│   ├── image
│   │   ├── faceDetection.ts   # Face detection logic
│   │   ├── blurFaces.ts       # Blurring faces in the image
│   │   └── fileUtils.ts       # File handling utilities
│   └── types
│       └── index.ts          # Type definitions for the application
├── package.json              # NPM configuration and dependencies
├── tsconfig.json             # TypeScript configuration
└── README.md                 # Project documentation
```

## Installation

1. Clone the repository:
   ```
   git clone <repository-url>
   ```
2. Navigate to the project directory:
   ```
   cd face-blur-gui-app
   ```
3. Install the dependencies:
   ```
   npm install
   ```

## Usage

1. Run the application:
   ```
   npm start
   ```
2. Use the GUI to open an image file.
3. The application will automatically detect faces in the image.
4. Select the faces you want to blur and apply the effect.
5. Save the modified image with a new filename.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License.