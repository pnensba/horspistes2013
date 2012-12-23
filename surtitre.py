#!/usr/local/bin/python3
import os
import gui_text_tk
try: import Tkinter
except: import tkinter as Tkinter
import vsosc

class Surtitre(gui_text_tk.Text_tk):
	def __init__(self, tkroot):
		self.tkroot = tkroot
		gui_text_tk.Text_tk.__init__(self, tkroot)

		self.mark_set(Tkinter.INSERT, "1.0")
		self.focus()

	def keyb_pressed(self):
		l = self.get_line()
		#print (l.encode('unicode-escape').tobytes)
		msg = l.encode('unicode-escape').decode('ascii')
		vsender.send('/osc',msg)

	def save(self, event=None):
		txt = self.get('1.0',Tkinter.END)
		print ('should save', txt)

	def read_line(self, event=None):
		line = self.get_line()
		print ('read line', line)

	def read_line_after_return(self, event=None):
		line = self.get_line_after_return()
		print ('read line', line)

	def read_text_after_return(self, event=None):
		return
	

if __name__ == "__main__":
	vsender = vsosc.Sender('127.0.0.1', 9001)
	tkroot = Tkinter.Tk()
	# tkroot.wm_attributes('-alpha',.5)
	tkroot.title('surtitre')
	# tkroot.attributes('-alpha', 0.5)
	#tkroot.geometry("800x600")
	#tkroot.geometry("800x500")
	tkroot.geometry("640x480")
	# tkroot.geometry("640x480+0+800")
	surt = Surtitre(tkroot)
	tkroot.mainloop()
