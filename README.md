# ChromaPy

ChromaPy is a small ChromaSDK Extension for Python.

Usage
--------
As simple as 
```
import ChromaPy as Chroma

RED = (255,0,0)

Chroma.setColor(RED) 
```
For further information take a look at the wiki of this repo. You can also find multiple examples in the "Example Script"-directory.


Building
--------

To compile it by your own don't forget to include the "include\" and the "libs\" directories of your Python Instance.

A compiled version of ChromaPy for Python 3.6 can be found on the official [Insider thread][insider].

Dependencies
------------

ChromaPy depends on the "Razer Chroma SDK", "SFML-Library" and "JSON for Modern C++".

The "Razer Chroma SDK" is provided by Razer and [can be found on their Website][rzdev].
The "SFML-Library" is provided by Laurent Gomila and [can be found on his Website][sfml].
"JSON for Modern C++" is provided by Niels Lohmann and [can be found on his Repo][nloh].


License
-------

Copyright &copy; 2017 by [Tim Gebauer][vaypron].

This project is licensed under the MIT license, please see the file **LICENSE** for more information.

Razer is a trademark and/or a registered trademark of Razer USA Ltd.  
All other trademarks are property of their respective owners.

The "SFML-Library" is provided under the [zlib/libpng License][zlib].

"JSON for Modern C++" is provided under the [MIT License][mit].








[vaypron]: https://github.com/Vaypron
[rzdev]: http://developer.razerzone.com/chroma
[mit]: https://github.com/nlohmann/json/blob/develop/LICENSE.MIT
[zlib]: https://www.sfml-dev.org/license.php
[sfml]: https://www.sfml-dev.org/index.php
[nloh]: https://github.com/nlohmann/json
[insider]: https://insider.razerzone.com/index.php?threads/beta-release-chromapy-python-extension-for-the-chroma-sdk-windows.18938/#post-324752
