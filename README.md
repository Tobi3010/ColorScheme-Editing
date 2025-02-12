# ColorScheme-Editing

This is a work in progress project. The goal is to make a program that can read the color scheme of a image, 
in different formats, and allow the user to edit the color scheme by rotation it around the colorwheel, and maybe
even allow to go from one color scheme to another, from monocromatic to analogous, from complimentary to 
split-complimentaary, etc.

## Things To Implement
- Colorwheel GUI (QT?)
  - Translate RGB to HSV
  - Colorwheel coordinates
- Read & print colors from image onto colorwheel 
  - Research color fresh holds, when do we diffenriate between colors?
- Colorscheme detection
  - Detect clusters of colors on colorwheel
  - Make "pizza cut" for each cluster
  - Placement of pizza cuts, determines color scheme (two cluster oposite eachother is complimentary, etc.)
- Highlight colors from colorscheme
  - If blue-orange split-complimentary colorscheme, clicking on orange pizza cut, highlights all orange colors on image,
  clicking on blue pizza cut, highlights all blue colors.
- Rotate colorscheme around colorwheel
  - Image keeps colorscheme, but with different colors 
  - Grayscale value must stay the same
- Translation between similar colorschemes 
  - Monochronomatic to analogous (and reverse)
  - Complimentary to Split-complimentary to triad (and reverse)
