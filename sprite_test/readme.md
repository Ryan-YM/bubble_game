gcc -c *.c 

g++ -c *.cpp 

g++ *.o -lgdi32 -lole32 -loleaut32 -luuid -lwinmm -lmsimg32 -o sprite.exe


### GAME RULE

get highest score in the limited time or life period

* heart     + 1 life sheild
* diamond   + 1 socre
* biohazard - 1 life sheild

### todo list
- [ ] 修正collision 判定
- [ ] 完善游戏记分
- [ ] 完善游戏结束机制
- [ ] 

#### guide words
Move Red Eye to catch Black Diamond with 1 score each one.
Every 20 scores will enlarge your compacity of your Eye.
Ones who reach 50 socre in limited time (maybe 2mins), will win this game,
otherwise, you lose.