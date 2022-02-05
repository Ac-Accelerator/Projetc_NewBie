
import pygame
import sys
class game:
    def __init__(self):
        pygame.init()#初始化背景数据，让pygame能够正常运行
        self.screen=pygame.display.set_mode((800,600))#创建一个800x600的显示窗口
        pygame.display.set_caption('逗比程序')#程序名字
        self.bg_color=(230,230,230)#背景颜色

    def run_game(self):
        
        while True :
            self._check_event()
            self._update_screen()

    def _check_event(self):
        for event in pygame.event.get():
                if event.type==pygame.QUIT:#如果单击了关闭按钮，退出
                    sys.exit()
    
    def _update_screen(self):
        show_text(self.screen,(100,100),'我的宝贝，我爱死你了，请你做我女朋友',(227, 29, 18),80)
        

   
def show_text(screen, pos, text, color, font_size=30):
    cur_font = pygame.font.SysFont("SimHei", font_size)  # 设置文字样式
    text_fmt = cur_font.render(text, True, color)  # 设置文字内容
    screen.blit(text_fmt, pos)  # 绘制文字

ai=game()
ai.run_game()