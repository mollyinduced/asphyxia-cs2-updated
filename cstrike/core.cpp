﻿/*

note: imgui crashes the game whenever esp is on and you interact a lot with the ui, i don't know what it is but has to be something with how components-
are rendered and overlap, going to try and fix in upcoming updates and keep the base as is just with fixes.

(faq)
1. reason im maintaing this : for fun, and learning purposes, want to learn more on internal cheats and reverse engeering.
2. what do you plan on doing with this : fix everything that is fucked with this. not at once but overtime with learning.
3. if this gets abandoned then what? : i don't fk, just move on its the big 25 and your looking at a paste src.. learn like i am or just cope.

    ⡏⡽⢩⢇⡳⣉⡞⣡⢏⡼⢱⡩⢎⡵⣙⠬⢳⣉⢞⣡⡛⣬⢳⡩⢞⣡⢛⡬⢳⣉⢞⣡⢛⡬⢳⣉⠞⣥⢛⡬⢳⡩⢞⣡⢛⡬⢳⡩⢞⣡⢛⡬⢳⣉⠞⣥⢛⡬⢳⣉⢞⣡⢛⡬⢳⣉⢞⣡⢛⡬⢳⣉⢞⣡⢛⡬⢳⡩⢞⣡⢛⡬⢳⣩⢚⡥⣛⢬⢳⡩⢞⣡⢛⡬⢳⣉⠞⣥⢳⡩⢞⣡⢳⣉⠶⣉⠞⣌⡳⣍⡚⣥⢋⡼⡘⢦⣙⡼⠸⢷⣌⠳⣌⢣⡝⢬⣙⢣
    ⡽⣘⢧⢫⡔⣣⠞⡱⢎⡴⢫⡔⡫⢴⡩⢞⡱⢪⡜⢦⢹⡐⢧⡚⢥⡚⣬⢒⠧⡜⢮⡰⢫⠴⠳⣌⠻⡰⣍⢲⠣⣕⠫⣔⠫⡴⢣⠳⣍⠲⣍⢲⠣⡎⠽⡐⢧⡚⠵⣘⢎⡲⢍⡲⢣⡚⣬⠲⣍⢲⠣⡞⢬⠲⣍⢲⢣⡱⢫⠔⣣⠚⡕⡢⢏⡴⢣⡚⢦⡱⢫⡔⢫⠴⢣⠎⡽⡐⢧⡚⣥⠚⢦⡹⢜⣡⠻⣔⢣⠖⡹⢤⣋⠖⣙⡶⠋⠀⠀⠘⢿⣷⣌⢣⢎⡕⡪⢵
    ⠶⡩⢞⡰⢎⡥⢫⡱⢩⡒⢇⡺⡑⢧⡙⢦⢹⡡⠞⣌⢣⡝⢢⠝⣢⡙⡤⢋⡜⣡⠳⣌⢣⡍⢳⢌⢳⠱⣌⢣⠹⣄⢛⡤⢛⡔⢫⡱⢌⠳⡘⢦⡙⡜⡱⡩⢆⡍⢳⢡⡚⡔⢫⠜⣡⠝⡰⢃⢮⢡⣋⠜⡥⢓⢬⢊⠵⣈⢇⡫⢔⡫⢜⡡⢏⡔⢣⡜⢢⣃⠧⡜⢣⢋⠵⢪⠱⡙⢦⡙⡤⢋⠧⡜⣊⠖⣙⠆⣏⡚⠵⢣⣜⠞⠉⢀⠀⠀⠠⢈⠲⣹⣟⣮⠜⣬⠱⣻
    ⢧⡙⡎⣕⢋⠖⣣⠕⣣⠝⣪⢱⡙⢦⡙⢎⡲⢡⡛⡌⠶⣘⢣⡙⡤⢓⡜⡱⢌⢣⠓⡌⠶⣘⠱⣊⢎⡱⢌⠲⣉⠦⣉⠖⡩⢜⡡⢚⡌⢣⡙⠦⡙⠴⣡⠓⡜⣌⠓⢦⡙⣌⠣⢎⡱⢊⠵⣉⢎⠲⣌⠚⣌⠣⢎⡜⡸⡐⢎⡔⠫⡔⣩⠒⡥⢊⠵⣈⠧⡘⢦⡙⡌⢎⡜⢣⡙⡜⢢⠕⣪⡙⡜⢲⡉⢮⡑⢞⡰⡙⣎⡷⠁⠀⠀⢂⣠⣴⣶⣧⣧⡑⡞⣻⣿⣤⠛⣼
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠉⠉⠛⠛⠻⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣱⠀⠐⣬⣿⣿⣿⣿⣿⣿⣻⢷⣥⢚⢿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠐⠀⠀⠁⠤⠁⣀⠀⠀⠀⠀⠈⡙⣛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⢼⠁⣼⣿⣿⣿⡿⠿⠹⠲⢭⠛⡼⣫⣾⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣁⠃⠀⠀⠀⠀⠀⠠⠀⠄⠀⠀⠠⢱⠘⣮⣛⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢎⣼⣿⣿⣿⠯⠔⣂⢓⡄⣀⣼⣾⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡍⢰⠀⠀⠀⠀⠀⡄⢢⡅⣮⡔⣦⣦⣤⠘⢰⠛⣷⣭⠛⣿⣿⣿⣿⠛⠛⠙⣧⣾⣿⡟⠋⢡⣦⣵⣮⣷⣽⠛⠛⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⡜⠠⠀⠀⢠⡐⣦⣽⣾⣽⣿⣿⣿⣿⣿⣿⣷⣾⣧⣿⣽⣮⣍⡐⢈⠀⡄⣤⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⡉⢒⢠⣾⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠱⣈⠃⢀⡸⢦⣿⣿⣿⣿⣿⣿⣿⡿⢿⣿⣿⣿⠿⠛⣟⣻⣯⣿⣷⣼⣾⣾⣿⣿⣿⣯⡝⢿⣿⡿⣤⠤⡀⠀⢀⢢⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⢣⠃⢠⢎⣽⣿⣿⣿⣿⣿⠟⠋⢡⠉⠊⣁⣤⣴⣾⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⢼⣹⢧⣚⢤⣰⣾⣿⣿⣿⣿⣿⣿
    ⡿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⠿⡛⣌⠃⢠⠧⣿⣿⣿⣿⠿⢛⡐⡎⠀⢠⣴⣿⣿⣿⣿⡿⢿⡟⢆⣿⣿⣿⠿⠿⠿⠿⠿⠿⠿⢿⡗⢮⣻⢯⣿⣟⣿⣿⣿⡿⠿⠿⠿⠿
    ⡼⣑⢫⠎⡽⢬⡙⢎⡱⡍⢎⡱⢊⡕⢪⡑⢪⠑⡬⢑⡊⡕⠬⡑⢪⠱⢨⡑⢪⠑⣌⢣⢊⠵⣨⠑⣪⠑⡬⢑⡌⠦⣉⠦⡑⠬⡘⠤⣃⠜⣠⠣⡘⠤⢃⠜⣠⠣⣘⠢⡑⢌⠢⠱⣌⠢⡑⢌⢢⠱⣈⠦⡑⢌⢒⠡⡚⢄⠣⠷⢿⢶⠿⠿⠿⢿⠿⠻⢿⡻⠋⡀⢔⣻⣿⣿⡿⡟⠉⣰⢣⠞⣬⢿⣿⡷⣈⠖⣩⠒⣍⠲⣉⠦⣙⠷⣯⣿⣟⣿⣿⣿⣟⠥⣛⢬⡙⢾
    ⡕⢣⡓⢮⠱⢆⡙⢦⠱⡜⢢⡑⢣⠜⡡⠜⣡⠙⡰⢣⠰⣑⠪⣑⢡⠃⡇⠜⣡⠙⡤⢃⠎⡒⢡⠓⠤⠓⡌⣡⠘⠴⣁⠒⡡⠓⣌⠱⢠⠓⡄⠓⣌⠱⢡⠚⠤⡑⢄⠣⡘⢄⢓⣽⣧⣃⠱⡈⢆⠱⢠⠒⡡⢎⠰⢃⠜⡠⠓⣌⢢⢘⠰⣉⠒⣌⠢⣍⣦⢣⡱⣘⢌⡻⢿⡹⢧⢹⠀⢿⣌⡻⣜⢮⡿⡒⠤⠓⡤⢋⡔⠣⡜⢢⢱⢊⠴⣌⢋⡟⣛⠿⣡⠚⣥⠲⣙⢺
    ⢭⢳⡘⢎⡳⢊⡵⢊⠳⣌⢣⠜⡡⢎⠱⢃⠦⡙⠴⢡⠓⡤⢓⢌⢢⡙⠴⣉⢆⠓⡌⢆⢣⠉⢦⠙⣢⠓⡰⢂⠝⡐⢢⠡⢣⠑⢢⠉⣆⠱⢌⡑⢢⠘⢆⠩⢂⠱⡈⢆⠱⣈⣿⣿⣿⣷⡱⢈⢌⡘⢄⠣⠱⣀⠣⡘⢢⠑⡩⢐⠢⢡⠒⠤⣉⣤⡿⡵⢎⡗⣧⢏⣦⡙⢎⡙⢦⡉⠄⠀⠉⠓⢉⣾⣿⢉⢎⡱⣘⠢⡜⡱⢌⢣⠚⣌⠲⣌⠺⡰⢡⡓⣆⡛⢤⠳⣡⢻
    ⢧⢲⡙⢎⡴⢋⡴⣉⠞⡤⢃⢎⡱⢊⡱⣉⠲⢡⢋⠦⣙⠰⣉⠆⡣⠜⢢⠱⢌⠱⡘⢂⢇⡙⠤⠓⡄⢓⡐⢣⠘⣌⠱⣈⠣⡘⢡⠚⢠⠊⢆⡘⠤⡉⠦⠑⡌⢢⠑⡨⢴⣿⣿⣿⢿⣿⣿⡔⣨⠐⡌⢢⠱⣀⠣⡘⢄⠣⢑⠢⡑⢢⢉⢒⠸⢻⣿⣿⣿⣜⣧⣛⡶⣻⢮⡼⣄⣡⢂⡜⣠⢰⣼⣿⢋⡌⡒⢤⡑⠎⡔⢣⠚⡤⢋⢆⠳⣌⢣⠱⢣⠕⡬⣑⢣⠓⡥⢻
    ⡎⡵⢚⡜⠴⣃⠶⣉⠞⡰⢩⢆⡱⢃⠴⡡⡙⢆⡩⢒⠬⡑⣌⠲⠱⢌⢣⠑⢪⠑⣌⠣⢌⠒⡩⢒⡑⢆⡉⢆⠩⡐⢢⢁⠒⡡⢂⠍⢢⠉⡔⢨⠐⡡⢌⠱⣀⠣⠘⣤⣿⣿⡿⣁⠋⢿⣿⣿⣆⠒⡈⠆⢒⠠⡑⠰⡈⢆⠡⢂⡑⠢⠌⣂⠉⠆⡌⢜⠻⣿⣷⣯⣷⣯⢿⣽⣻⣟⣿⣻⣽⣿⣿⠡⠒⣌⠱⠢⢜⡱⡘⡅⢫⠔⡩⢎⡱⢢⢍⢣⢋⡜⡱⣌⢣⠛⡜⣹
    ⠼⣱⢋⡜⣱⢊⠖⡱⢊⡕⢣⠒⡜⣌⠲⡑⢜⠢⡑⢎⡰⠑⣌⠒⡍⠒⡌⢣⢑⢊⠔⠣⠜⡰⡑⢢⡘⠤⡘⢄⠣⡘⠤⠊⡔⢡⠊⠜⡠⢃⡘⠄⢣⠐⡌⢂⠔⣈⣱⣿⣿⡿⡡⠐⡌⡘⣿⣿⣿⣦⡑⠋⡄⢃⠌⡑⠰⡈⢢⠡⠌⡑⠌⠤⣉⠒⢌⢂⠱⣀⢋⠛⣿⣿⣿⣾⣷⣯⣟⣿⣿⠟⢡⠊⡕⠨⢜⠱⢢⡑⢜⡈⢇⢎⠱⣊⠴⣃⠮⣡⠳⡌⢵⡈⣇⠛⣬⢹
    ⡳⢜⡲⢜⢢⢍⡚⠥⡓⡜⣌⠣⢒⠤⢣⡙⣌⠣⢜⠰⣈⠓⡤⠓⢬⠑⡜⡐⢪⠤⡙⠰⣉⠔⡑⢢⠘⡰⢁⠎⡰⢁⠎⡁⢆⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⡠⢄⠩⡐⠌⡒⢄⠊⡅⠢⢄⡙⢛⠿⣿⣿⠟⡡⢊⡄⢓⠌⡱⢊⠥⢣⠜⢢⠍⡪⢌⡱⢢⠱⣌⠲⣡⠓⡜⣡⠞⡰⢫⠔⣻
    ⡓⢮⡜⡜⡜⢪⠜⡱⡘⠴⣈⠧⣉⠲⢡⠒⣌⠚⡌⢒⡡⢓⡰⢉⠦⡑⢢⢉⠲⣈⠔⣃⠒⠬⠰⡁⠞⣀⠣⡘⢄⠣⢘⠰⡈⢂⠍⢿⣿⣿⣟⠛⠟⡛⠟⠻⣿⣿⣿⡟⠟⠻⠛⠟⠻⠛⠟⠻⢻⣿⣿⣿⡛⠟⠻⠛⠟⣻⣿⣿⡿⢁⠣⡐⢌⠢⠑⡌⠰⡈⢆⠡⢃⠆⡘⢄⠪⢄⡡⢊⠔⡡⢘⠂⢎⠱⡉⢆⢣⠚⡤⢣⡑⠎⡔⢣⠓⡬⡑⢆⡛⡜⢤⢋⡕⣣⢚⣹
    ⡝⣲⢸⠰⣍⠦⡙⠴⣉⠖⣡⢒⢡⢃⢣⢉⠦⠱⡨⠑⡆⢣⢐⢃⠦⡑⢣⠘⡔⢢⠚⡠⣉⠒⡱⢈⠖⡠⢃⠜⡠⢊⠔⡁⠦⣁⠊⠜⣿⣿⣿⣎⡰⢁⣘⣿⣿⣿⠏⠡⢌⢁⠚⢨⠡⢑⠨⢁⠆⢻⣿⣿⣷⡈⠅⡱⣸⣿⣿⡟⡑⠌⡐⡐⠢⡁⢎⠐⡱⠈⢆⡑⢊⠔⡡⢊⠔⡡⢂⠣⣘⠰⣁⠋⡜⢢⠙⢤⢊⠕⡬⢡⠜⡱⢌⢣⠚⡔⣙⠦⡱⢜⡘⢆⡣⢓⠼⣸
    ⣚⠴⣩⠖⡜⢢⣙⠱⣌⠚⢤⢃⠎⡜⢢⠣⡘⠱⡰⢉⡜⠰⡊⠴⡘⠰⢃⠱⣘⠢⠱⡁⠦⡑⠤⡉⢆⠱⡈⠆⡑⠢⡘⡐⠰⢠⠉⡔⢈⢻⣿⣿⣧⢢⣿⣿⣿⢃⡉⠆⢌⠂⡑⠂⡜⢀⠃⢆⠨⠄⢛⣿⣿⣿⡤⣵⣿⣿⡟⢂⠡⡘⢠⠡⡑⠰⡈⠒⡄⠋⡔⣈⠒⡌⠔⡡⢊⠔⣡⠚⢄⠓⡌⢒⡸⢠⢙⠰⣊⠜⡰⢃⡜⢡⠚⣆⠹⡰⢡⢎⡱⢊⠼⣌⠳⣍⠲⣹
    ⢣⢏⠴⡚⣜⠡⢎⡱⢨⠍⣆⠣⡚⢌⢢⠱⡉⠖⡱⢂⠬⡑⡸⠐⣍⠘⡌⠣⢄⢣⠱⡘⠰⡈⢆⠱⡈⢆⠱⡈⠴⠁⢆⡁⢃⠆⠱⡀⠎⠠⢿⣿⣿⣿⣿⡿⢃⠢⠐⡌⠰⡈⠔⣁⠒⡈⠜⠠⡁⠎⡐⠬⣿⣿⣿⣿⣿⠟⡈⠤⢁⡘⠄⢢⢁⠃⡔⠡⢌⡑⠰⣀⠣⢌⠢⡑⢌⠲⢠⢉⢌⠒⠬⣁⠲⡁⢎⠱⣈⠖⣡⠣⡘⠦⡙⢤⢓⡡⢓⠬⣘⢥⠚⡤⠳⣌⠳⣹
    ⠷⣎⢱⢱⡈⢷⠸⡰⢇⠾⡀⢇⠹⢆⢁⠇⠹⢆⠱⡎⢰⢱⡈⢇⠸⢰⢈⢱⠈⣆⠱⡈⢱⠈⣆⠱⡈⠆⣆⠱⡈⠸⣀⠸⡀⠎⢱⢀⠉⠶⢀⢿⣿⣿⣿⠁⢇⠈⣁⠈⢱⢀⠱⡀⢆⠁⡎⢁⠸⠰⠰⠆⠹⣿⣿⣿⡏⡈⠁⡆⢁⠰⡈⠆⡆⢁⠆⠱⢆⠈⢱⠀⡎⡀⢇⠸⣀⠷⡈⢆⠸⢸⠰⢆⢱⠁⡎⠱⢆⠇⡆⢇⠹⢰⠉⣶⡈⢶⢉⠶⣉⢆⡹⢰⠏⣶⢱⢹
    ⡳⣌⠳⢆⡹⢢⡙⠴⣉⠦⡙⣌⠲⡌⠲⡌⠳⣈⠲⣈⠥⢂⡜⠢⠍⣆⠸⡠⢋⡐⠦⢑⠢⡑⢄⠣⣘⠰⢠⠂⣅⠣⠐⠤⡑⠌⢢⠈⡌⠒⢬⣿⣿⣿⣿⣯⡄⠓⡠⠚⡀⠆⡡⠐⡌⠰⡐⡈⢄⠃⡡⢊⣽⣿⣿⣿⣿⣤⠉⢆⠘⡠⢁⠎⠤⣁⠊⢅⠢⡉⠔⡨⢐⢡⠊⡔⢠⢂⡱⠨⢜⠢⣉⠆⢢⠓⢬⢑⠪⡜⠸⣈⠣⣅⠫⢔⡸⠌⣎⠲⣡⠎⡴⢋⠞⣤⢣⢻
    ⡵⣌⢫⢆⡝⢢⡙⢦⠑⢦⠑⢦⠱⢌⡱⢌⠱⢠⢃⠦⡘⢆⠬⢡⡙⢄⢣⠑⣢⠱⣈⠦⡑⢌⢢⠑⡄⢃⠆⡡⢂⢌⡑⠂⡅⢊⠤⢁⢢⣹⣿⣿⡿⢟⣿⣿⣷⣁⠒⠡⡘⠤⢁⢃⡘⠐⠤⢁⠢⠘⣠⣿⣿⣿⠏⢿⣿⣿⣇⢂⠱⡀⢣⠈⠆⠤⡉⠔⣂⠡⢊⠔⡡⢂⡱⢈⠆⡒⢌⠱⣈⠒⣡⠊⡥⢊⡔⢊⠲⢌⠳⢄⠳⣄⢋⠦⡱⢩⠔⡳⡰⢍⢲⡉⡞⣤⢣⢻
    ⠶⣌⢣⢎⡜⢥⠚⡤⢋⠦⣙⢢⠙⡤⢒⠌⡚⢄⠣⢆⢩⠢⢌⢣⠘⢤⢊⡒⠤⡃⡔⢢⠑⡬⢠⠣⡘⢄⡊⠔⡁⠆⡌⡑⢨⠐⣂⠡⣲⣿⣿⡟⠇⡠⢙⣿⣿⣿⡎⠅⠴⢈⢂⠆⢌⡘⢄⠃⡌⣡⣿⣿⣿⠃⠎⠌⢿⣿⣿⣦⠑⢢⠁⠎⢌⠒⡨⠐⠤⡉⢆⡘⢄⠣⢄⠣⡘⠔⣌⠢⢅⠣⢔⢡⠚⡰⡘⢌⠳⠌⡜⡌⢣⠔⣊⠖⣡⢣⠚⡥⢓⡌⣣⠜⡱⢆⢣⢻
    ⠳⣌⢧⢊⡜⢦⡙⡴⣉⠖⡌⢦⠙⡤⣉⢒⠩⢌⠲⣈⠦⡑⠪⢄⢫⢐⠢⠜⡰⢡⠜⡠⢣⠰⣁⠒⣡⠂⡜⢠⠑⡌⠰⡈⢄⠃⠤⣾⣿⣿⣟⣤⣃⣅⣢⣜⣿⣿⣿⣬⣅⣎⣤⣊⣤⣌⣦⣡⣴⣿⣿⣿⣅⣎⣜⣌⣌⣻⣿⣿⣿⠠⡘⠌⢄⠣⡐⢩⠐⡌⠰⡐⢌⠒⡌⢰⢁⠎⢤⠃⡌⢎⢒⢢⠩⠔⣉⠆⢳⠘⡴⢡⢃⠞⣠⢋⡔⢣⠹⣐⢣⠜⣰⢩⡓⢎⡥⢻
    ⢏⡜⢦⠭⣘⠦⣑⠖⡌⢖⡘⠦⣙⠰⣈⠦⣉⠦⡑⢢⡘⢤⠋⡔⢢⠎⡱⢘⠔⡡⠚⡄⢃⡒⠤⢃⠢⡑⠌⡄⢣⢀⠣⠌⢂⢜⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡔⡈⢆⠢⢑⠢⠡⢌⡑⢌⢢⠑⣌⠢⢎⡘⠤⢣⠘⡌⠆⢆⡹⠌⡔⣊⠱⣘⠰⢃⡜⢢⡑⢪⠜⢢⠛⣤⠓⣎⠱⡆⣝⠲⣌⢻
    ⣇⠺⡜⠦⣍⠖⣡⠞⡘⢆⡹⠰⣌⠣⢔⠢⡅⢆⠱⣂⠜⡠⢓⠌⡒⠬⢰⠡⢎⠴⢩⠐⣡⠘⢢⠡⢓⠨⡘⠤⡁⢎⢠⠉⢆⠸⢉⡉⢉⡉⢉⡉⢉⡉⣉⢉⡉⡉⣿⣿⣿⣯⢉⡉⣉⠉⣽⣿⣿⡟⣉⠉⣉⠉⣉⠉⣉⠉⣉⢉⡉⡉⢍⡐⢂⠡⡂⢅⠃⢆⡘⢄⢢⠱⣀⢣⢂⠜⡘⠤⢋⠴⣉⠦⡘⠴⢱⡈⠵⣈⠱⢣⠘⣆⠙⢦⡙⢦⡙⢤⠫⣔⢹⡐⣣⠳⣌⢻
    ⡬⣓⡹⢦⡙⡜⢢⢣⡙⢦⡑⢣⠔⢣⠎⡱⢘⠤⣃⠦⡘⠤⢋⠴⠱⡘⢢⢑⡊⠔⢣⡘⢤⡙⠤⢃⡜⢠⡑⢢⠑⡄⢢⠉⡄⢃⠆⡘⢠⠂⠥⡈⠆⠰⡀⠆⢄⠡⡈⠽⣿⣿⣷⠠⡐⣿⣿⣿⠟⡐⢠⠑⡠⢃⠄⢃⠤⢉⠰⡀⢆⠡⢂⠔⢡⢂⠱⡈⠜⡠⠜⡠⢢⢑⢂⠆⣊⠦⣉⠦⣉⠲⠰⢌⡱⢊⠲⣨⠱⢌⠳⢌⠳⣈⠝⡢⢜⢢⡙⢦⠹⣄⠳⣌⢣⠳⣌⢻
    ⡵⣑⠺⣤⡙⣬⠓⢦⡙⢦⡘⢥⠪⢅⢎⡱⢌⠒⡤⢓⠸⣈⠣⢌⡱⢘⠢⢆⠜⣘⠢⢜⡠⠜⣄⠣⢌⢂⡜⢠⠃⡜⢠⠃⡌⢂⠜⢠⠁⢎⡐⠡⢌⠡⡐⠩⣀⠃⡄⠃⠿⣿⣿⣷⣾⣿⣿⠏⡒⢨⠐⢂⠡⢂⠜⢠⠂⡅⢢⠁⢆⠱⢈⠆⢢⠌⢢⠑⡬⠐⣅⠢⢃⠜⢤⠚⡐⢆⠲⡰⢌⡸⠱⣌⠲⣉⠲⣁⠞⣄⠫⡔⢣⠜⡬⡑⢎⠦⡙⢦⠹⣄⠯⣐⢇⡳⢌⣻
    ⣖⡩⢞⡤⡹⣄⠻⡤⣙⠦⡙⡤⢋⠆⢎⡔⢪⠑⡜⠤⢓⠤⣉⠖⡌⢢⠍⢆⠚⡄⠳⠠⠜⡰⢄⠣⠜⡠⡘⢄⢣⠘⠤⡑⢌⠢⡘⢄⠩⠄⡌⡑⢌⢂⠡⡑⢠⠁⢆⠩⡐⠹⣿⣿⣿⣿⠏⠤⠑⢂⠩⢄⠣⢌⠢⡁⢎⡐⢡⠘⡄⠣⢌⡘⢄⠪⡄⠣⢌⠱⣀⠣⢎⡘⠤⢣⡘⠤⢓⡰⢌⠔⡣⢆⠳⢄⠳⠤⡙⠤⡓⢌⢣⠚⡴⣉⠎⡖⡙⢆⡳⣌⠶⡡⠞⣬⢓⣼
    ⢦⡓⣭⢒⡱⣌⠳⣔⢡⢎⡱⡘⣌⠚⡴⢨⢡⢋⠴⣉⢆⠒⣌⠒⣌⠒⡌⢎⡘⢌⡡⢋⠔⡱⢨⠜⡠⢃⠜⡨⢐⠌⢢⠑⡌⢢⢁⠎⡰⢁⠒⡌⠰⡈⢆⠑⡂⢍⠠⢃⠰⠡⡙⣿⡿⢣⠘⠤⢉⠢⡁⢆⡘⢄⠢⡑⢠⠘⡄⢃⡘⡐⢢⠌⡌⢒⠨⡑⢌⠒⣄⢃⠆⡜⢄⢣⠘⣌⠡⢜⡈⢎⡱⢌⠒⡍⡜⢢⢍⠒⡍⡜⢢⡙⢴⡈⢞⡰⢍⠮⡔⡜⢲⡡⢛⡤⢳⢼
    ⠧⡜⠦⣍⠶⣌⠳⡌⠶⣌⠲⡱⢌⡱⢂⠇⡆⢣⠒⡴⢈⠎⠤⢋⠤⢣⠘⢆⡘⢆⡘⠦⡘⠔⡡⢎⠰⡁⠎⡔⠡⢎⠰⡉⠴⣁⠊⡔⢡⠊⠴⣈⠱⡐⢌⠢⠱⡈⠦⢡⠊⠵⢐⠸⡓⠄⢣⠘⡄⢣⠘⠤⡈⢆⠱⡈⢆⠡⡘⢄⠢⡑⢢⠘⡄⢃⠦⠑⡌⠒⠤⢊⠴⣈⠒⢆⠱⢂⡍⠦⡘⢆⠲⢌⠣⢜⠰⡃⢬⢚⠰⢍⠦⡙⢤⡙⢦⡑⢎⠖⡱⢎⠥⣓⠭⣒⢭⢺
    ⣷⣾⣷⣾⣶⣾⣷⣾⣷⣾⣷⣷⣾⣶⣿⣶⣿⣶⣷⣶⣿⣾⣷⣾⣶⣷⣾⣶⣾⣶⣾⣶⣷⣾⣶⣾⣶⣷⣾⣶⣿⣶⣷⣾⣶⣶⣷⣾⣶⣿⣶⣶⣷⣾⣶⣷⣷⣾⣶⣷⣾⣶⣷⣶⣷⣾⣶⣷⣾⣶⣿⣶⣷⣾⣶⣷⣾⣶⣷⣾⣶⣷⣶⣷⣾⣶⣾⣷⣾⣷⣾⣷⣶⣶⣿⣶⣷⣾⣶⣷⣾⣶⣿⣶⣿⣶⣷⣾⣶⣾⣷⣾⣶⣿⣶⣿⣶⣿⣾⣾⣷⣾⣷⣾⣾⣶⣷⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
    ⣿⣿⣿⣿⡿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⢿⣿⡿⣿⣿⢿⣿⣿
    ⣖⢢⠖⣔⢣⠖⢦⠜⣒⠦⢲⡰⢆⡖⢴⢂⠶⣐⢦⡒⢆⡲⢔⢢⢖⡰⢆⡲⣐⠆⣖⠰⢆⠲⡔⢢⢒⠴⣐⠢⣔⠢⡔⢤⠢⡔⢤⠢⡔⢤⠢⡔⢤⢂⠴⣀⠦⡐⢤⢂⠴⣀⠦⡐⢤⢂⠴⣀⠦⡐⢤⢂⠴⣀⠦⡐⢤⢂⠴⣀⠦⡐⢤⢂⠴⡠⢆⠴⣠⠒⣤⠢⡔⡢⢔⢢⢒⡔⢢⢒⡔⡢⢖⡰⢆⠲⡔⡲⢔⡢⢖⡴⢢⠖⢦⡒⢦⡱⢲⠌⣖⢢⡓⢦⡜⡲⠴⣸
    ⣎⢣⡛⢬⢣⣋⢮⡙⣬⢓⡣⠵⣩⢜⢣⡍⢞⡡⢎⡱⣋⠴⣋⢎⠮⣔⢫⠴⣉⠞⣌⡓⢎⡳⢸⣡⢋⡖⣩⠱⣌⠳⣌⢣⠓⡜⢢⡓⡜⣢⠓⡜⢢⢍⢲⠡⢎⡱⢊⡜⢢⠱⣌⠱⣊⠜⣢⡑⢪⡑⢎⣌⠲⡡⢎⡱⢊⡜⡒⣌⢲⡉⢦⡉⢖⡱⢊⢖⡡⢋⡔⡳⢌⡱⢩⢆⢫⠜⣥⠣⢎⡱⢫⡔⢫⡱⢎⡱⣋⡜⢮⡔⣋⠞⣥⡙⢦⠓⣭⢚⢬⢣⡙⢦⠭⣑⢏⣼
    ⣎⢣⡝⣎⢣⡜⣢⠳⣌⠇⣞⡱⣱⢊⠷⣨⢧⡙⢮⢱⡩⢞⡸⣌⠳⣌⢧⡙⣬⠹⣤⢋⠶⣉⠶⡡⢏⡜⢥⡋⢦⡙⡴⣉⠞⣌⢳⡘⡴⣡⠫⡜⢥⢪⢬⡙⠼⡰⢍⡜⣡⠓⣌⢣⢥⢋⡴⣉⢦⡙⠦⣌⢣⡱⣊⠥⣋⠴⣉⢆⡣⢜⢣⡜⢥⣊⢭⢢⢣⢋⡴⣉⢮⡱⣍⠎⣥⠫⣔⢫⡱⣙⠲⡜⣣⠱⣍⠶⣱⢊⡳⡌⢧⠫⡴⡙⣬⠫⣔⠫⡜⣥⡙⢦⡛⣌⠮⣼
    ⢎⡳⢜⡜⢦⡙⡴⢋⡬⢫⡔⡣⠵⡩⢖⠥⣎⠹⣌⠇⣞⣡⠳⣌⢳⢊⠶⣉⠶⣙⢤⡋⣞⢡⢏⡱⣍⠺⡰⢍⠶⣉⠶⣉⠞⡌⠶⣉⠶⡡⢏⡜⢬⢃⠞⣌⠳⣉⠞⡸⢤⠛⡬⢃⠮⡑⢦⡑⢎⡜⡱⡌⠶⡱⢌⠳⣌⠳⡜⠬⡜⣡⠳⣘⠦⣉⠞⣰⠩⡖⣱⠩⢦⠱⡜⣚⠴⣙⢬⢣⡜⢥⡛⢬⠣⢏⡜⢣⡕⢫⠴⡹⣌⢳⣡⠛⡴⢋⡜⡣⡝⣤⢹⡂⠷⣌⠳⡼
																																	- mollyinduced
*/

// used: [win] shgetknownfolderpath
#include <shlobj_core.h>

#include "core.h"

// used: features setup
#include "features.h"
// used: string copy
#include "utilities/crt.h"
// used: mem
#include "utilities/memory.h"
// used: l_print
#include "utilities/log.h"
// used: inputsystem setup/restore
#include "utilities/inputsystem.h"
// used: draw destroy
#include "utilities/draw.h"

// used: interfaces setup/destroy
#include "core/interfaces.h"
// used: sdk setup
#include "core/sdk.h"
// used: config setup & variables
#include "core/variables.h"
// used: hooks setup/destroy
#include "core/hooks.h"
// used: schema setup/dump
#include "core/schema.h"
// used: convar setup
#include "core/convars.h"
// used: menu
#include "core/menu.h"

// used: product version
#include "sdk/interfaces/iengineclient.h"

// define status as false
extern volatile bool CORE::bIsUnloading = false;
extern bool CORE::bInitialized = false;

bool CORE::GetWorkingPath(wchar_t* wszDestination)
{
	bool bSuccess = false;
	PWSTR wszPathToDocuments = nullptr;

	// get path to user documents
	if (SUCCEEDED(::SHGetKnownFolderPath(FOLDERID_Documents, KF_FLAG_CREATE, nullptr, &wszPathToDocuments)))
	{
		CRT::StringCat(CRT::StringCopy(wszDestination, wszPathToDocuments), CS_XOR(L"\\.Leerware\\"));
		bSuccess = true;

		// create directory if it doesn't exist
		if (!::CreateDirectoryW(wszDestination, nullptr))
		{
			if (::GetLastError() != ERROR_ALREADY_EXISTS)
			{
				L_PRINT(LOG_ERROR) << CS_XOR("failed to create default working directory, because one or more intermediate directories don't exist");
				bSuccess = false;
			}
		}
	}
	::CoTaskMemFree(wszPathToDocuments);

	return bSuccess;
}

static bool Setup(HMODULE hModule)
{
	if (CORE::bInitialized)
	{
		L_PRINT(LOG_WARNING) << CS_XOR("Setup called but already initialized");
		return true;
	}

#ifdef CS_LOG_CONSOLE
	if (!L::AttachConsole(CS_XOR(L"Leerware developer-mode")))
	{
		CS_ASSERT(false); // failed to attach console
		return false;
	}
#endif
#ifdef CS_LOG_FILE
	if (!L::OpenFile(CS_XOR(L"leerware.log")))
	{
		CS_ASSERT(false); // failed to open file
		return false;
	}
#endif
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("logging system initialization completed");

	// setup game's exported functions
	if (!MEM::Setup())
	{
		CS_ASSERT(false); // failed to setup memory system
		return false;
	}
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("memory system initialization completed");

	if (!MATH::Setup())
	{
		CS_ASSERT(false); // failed to setup math system
		return false;
	}
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("math system initialization completed");

	// grab game's interfaces
	if (!I::Setup())
	{
		CS_ASSERT(false); // failed to setup interfaces
		return false;
	}
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("interfaces initialization completed");

	if (!SDK::Setup())
	{
		CS_ASSERT(false); // failed to setup sdk
		return false;
	}
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("sdk initialization completed");

	// setup input system and replace game's window messages processor with our
	if (!IPT::Setup())
	{
		CS_ASSERT(false); // failed to setup input system
		return false;
	}
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("input system initialization completed");

	// @note: sleep to wait finishing font building
	D::Setup(IPT::hWindow, I::Device, I::DeviceContext);
	MENU::UpdateStyle(nullptr);
	while (D::bInitialized == false)
		::Sleep(200U);
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("renderer backend initialization completed");

	// initialize feature-related stuff
	if (!F::Setup())
	{
		CS_ASSERT(false); // failed to setup features
		return false;
	}
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("features initialization completed");

	// iterate all valid modules for schema
	std::vector<std::string> vecNeededModules = { CS_XOR("client.dll"), CS_XOR("engine2.dll"), CS_XOR("schemasystem.dll"), CS_XOR("matchmaking.dll") };
	for (auto& szModule : vecNeededModules)
	{
		if (!SCHEMA::Setup(CS_XOR(L"schema.txt"), szModule.c_str()))
		{
			CS_ASSERT(false); // failed to setup schema system
			return false;
		}
	}
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("schema system initialization completed");

	if (!CONVAR::Dump(CS_XOR(L"convars.txt")))
	{
		CS_ASSERT(false); // failed to setup convars system
		return false;
	}
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("convars dumped completed, output: \"convars.txt\"");

	if (!CONVAR::Setup())
	{
		CS_ASSERT(false); // failed to setup convars system
		return false;
	}
	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("convars system initialization completed");

	// setup hooks
	if (!H::Setup())
	{
		CS_ASSERT(false); // failed to setup hooks
		return false;
	}
	L_PRINT(LOG_NONE) << CS_XOR("hooks initialization completed");

	// setup values to save/load cheat variables into/from files and load default configuration
	if (!C::Setup(CS_XOR(CS_CONFIGURATION_DEFAULT_FILE_NAME)))
		// this error is not critical, only show that
		L_PRINT(LOG_WARNING) << CS_XOR("failed to setup and/or load default configuration");
	else
		L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_GREEN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("configuration system initialization completed");

	// @note: this doesn't affect much, but it's good to know if we're using different version of the game
	if (CRT::StringCompare(I::Engine->GetProductVersionString(), CS_PRODUCTSTRINGVERSION) != 0)
		L_PRINT(LOG_WARNING) << L::SetColor(LOG_COLOR_FORE_YELLOW | LOG_COLOR_FORE_INTENSITY) << CS_XOR("version mismatch! local CS2 version: ") << CS_PRODUCTSTRINGVERSION << CS_XOR(", current CS2 version: ") << I::Engine->GetProductVersionString() << CS_XOR(". Leerware might not function as normal.");

	L_PRINT(LOG_NONE) << L::SetColor(LOG_COLOR_FORE_CYAN | LOG_COLOR_FORE_INTENSITY) << CS_XOR("Leerware initialization completed, version: ") << CS_STRINGIFY(CS_VERSION);

	// end of setup; mark as initialized
	CORE::bInitialized = true;
	return true;
}

// @todo: some of those may crash while closing process, because we dont have any dependencies from the game modules, it means them can be unloaded and destruct interfaces etc before our module | modify ldrlist?
static void Destroy()
{
	// prevent crashing because it isn't hooked (i've crashed somehow)
	if (!CORE::bInitialized)
	{
		L_PRINT(LOG_WARNING) << CS_XOR("Destroy called but not initialized");
		return;
	}

	CORE::bIsUnloading = true;
	// restore window messages processor to original
	IPT::Destroy();

	// restore hooks
	H::Destroy();

	// destroy renderer backend
	D::Destroy();

	// destroy chams dependent stuff
	F::Destroy();

#ifdef CS_LOG_CONSOLE
	L::DetachConsole();
#endif
#ifdef CS_LOG_FILE
	L::CloseFile();
#endif

	// define status of module in destroy func
	CORE::bInitialized = false;
	CORE::bIsUnloading = false;
}

DWORD WINAPI PanicThread(LPVOID lpParameter)
{
	// don't let proceed unload until user press specified key
	while ((::GetAsyncKeyState(C_GET(unsigned int, Vars.nPanicKey)) & 0x8000) == 0)
		::Sleep(10UL);

	// we only want this to run when we define the console (debugging feature)
#ifdef CS_LOG_CONSOLE
	L_PRINT(LOG_WARNING) << CS_XOR("panic key pressed, unloading...");

	// call destroy to kill hooks properly, this is for debugging
	Destroy();
#endif

	::Sleep(100);

	// call detach code and exit this thread
	::FreeLibraryAndExitThread(static_cast<HMODULE>(lpParameter), EXIT_SUCCESS);

	// considering but don't remember use.
	//return 0UL;
}

extern "C" BOOL WINAPI _CRT_INIT(HMODULE hModule, DWORD dwReason, LPVOID lpReserved);

BOOL APIENTRY CoreEntryPoint(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	// Disables the DLL_THREAD_ATTACH and DLL_THREAD_DETACH notifications for the specified dynamic-link library (DLL). This can reduce the size of the working set for some applications
	DisableThreadLibraryCalls(hModule);

	// process destroy of the cheat before crt calls atexit table
	if (dwReason == DLL_PROCESS_DETACH)
		Destroy();

	// dispatch reason for c-runtime, initialize/destroy static variables, TLS etc
	if (!_CRT_INIT(hModule, dwReason, lpReserved))
		return FALSE;

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		CORE::hProcess = MEM::GetModuleBaseHandle(nullptr);

		// basic process check
		if (CORE::hProcess == nullptr)
			return FALSE;

		/*
		 * check did all game modules have been loaded
		 * @note: navsystem.dll is the last loaded module
		 */
		if (MEM::GetModuleBaseHandle(NAVSYSTEM_DLL) == nullptr)
			return FALSE;

		// save our module handle
		CORE::hDll = hModule;

		// check did we perform main initialization successfully
		if (!Setup(hModule))
		{
			// undo the things we've done
			Destroy();
			return FALSE;
		}

		// create panic thread, it isn't critical error if it fails
		if (const HANDLE hThread = ::CreateThread(nullptr, 0U, &PanicThread, hModule, 0UL, nullptr); hThread != nullptr)
			::CloseHandle(hThread);
	}

	return TRUE;
}
