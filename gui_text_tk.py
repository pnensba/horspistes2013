try: import Tkinter 
except: import tkinter as Tkinter 
import time, os

class Text_tk(Tkinter.Text):

	def get_line(self, event=None):
		nol,trash =  self.getindex(Tkinter.INSERT)
		line = self.get('%d.0'%(nol),'%d.0'%(nol+1))
		line = line.strip()
		return line

	def get_line_after_return(self, event=None):
		nol,trash =  self.getindex(Tkinter.INSERT)
		line = self.get('%d.0'%(nol-1),'%d.0'%(nol))
		line = line.strip()
		return line

	def get_text(self, event=None):
		txt = self.get('1.0',Tkinter.END)
		return txt

	def insert_text(self, line,tag):
		nol, noc = self.getindex(Tkinter.INSERT)
		self.see('%d.0' % (nol+1))
		self.update()
		self.insert(Tkinter.INSERT, line,tag)
		self.insert(Tkinter.INSERT, '\n')
		self.update()

	def set_text(self, line, dursec=0):
		nol, noc = self.getindex(Tkinter.INSERT)
		if dursec==0:
			self.insert(Tkinter.INSERT, line)
		else:
			nblettres = len(line)
			nbsec_per_letter = float(dursec)/nblettres
			noc = 0
			for c in line:
				self.see('%d.0' % (nol+1))
				self.update()
				self.insert(Tkinter.INSERT, c)
				self.tag_add('set', '%d.%d'% (nol, noc) ,'%d.%d'%(nol,noc+1))
				noc+=1
				time.sleep(nbsec_per_letter)
				self.update()

		self.insert(Tkinter.INSERT, '\n')

		self.tag_add('set', '%d.0'% nol,'%d.0'%(nol+1))

	def getindex(self,pos):
		return tuple(map(int, str(self.index(pos)).split(".")))

	def noquit(self):
		return

	def quit(self, event=None):
		self.save()
		self.tkroot.destroy()
		
	def __init__(self, tkroot):
		self.tkroot = tkroot
		self.tkroot.protocol("WM_DELETE_WINDOW", self.noquit)
		# gui elements
		scrolly = Tkinter.Scrollbar(tkroot,
							command = self.yview,
							orient = Tkinter.VERTICAL)
		scrollx = Tkinter.Scrollbar(tkroot,
							command = self.xview,
							orient = Tkinter.HORIZONTAL)

		Tkinter.Text.__init__(self, tkroot,
					 # font=("helvetica", 16),
					 font=("helvetica", 32),
					 insertwidth=5,
					 insertbackground = "green",
					 selectbackground = "orange",
					 selectforeground = "white",
					 selectborderwidth = 0,
					 #wrap = "none",
					 wrap = "word",
					 fg = "white",
					 bg = "grey10",
					 highlightthickness = 0,
					 highlightcolor = "green",
					 highlightbackground = "green",
					 yscrollcommand=scrolly.set,
					 xscrollcommand=scrollx.set,
					 border=0, bd=0, relief=Tkinter.FLAT)
		
		#scrolly.pack(fill=BOTH,side=RIGHT)
		#scrolly.pack(fill=BOTH,side=LEFT)
		#c'etscrollx.pack(fill=BOTH,side=BOTTOM)
		self.pack(expand=Tkinter.YES, fill=Tkinter.BOTH)
		self.bind("<Control-q>",  self.quit)
		self.tkroot.bind("<Control-q>",  self.quit)
		self.tkroot.bind("<Control-space>",  self.read_line)
		self.tkroot.bind("<Return>",  self.read_line_after_return)
		self.tkroot.bind("<Control-Return>",  self.read_text_after_return)
		self.tkroot.bind("<Control-s>",  self.save)
		self.bind('<KeyRelease>', self.keyreleased)
		os.system("osascript -e ' set appID to %d\n tell application \"System Events\" to set frontmost of (every process whose unix id is appID) to true'" % os.getpid())

	def keyreleased(self, e=None):
		self.keyb_pressed()
			


