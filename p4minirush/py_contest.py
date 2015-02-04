#!/usr/bin/python

import os
import re
import shutil
import string
import random

MAIN = "main.c"
MAIN_TMP = "main_temp.c"
#COMPILE_L = "gcc -Wall -Werror -Wextra -o p4out -I kit_dev kit_dev/p4_tool.c kit_dev/p4_won.c %s challengers/%s challengers/%s 2> /dev/null"
COMPILE_L = "gcc -Wall -Werror -Wextra -o p4out -I kit_dev kit_dev/p4_tool.c kit_dev/p4_won.c %s challengers/%s challengers/%s"

def id_gen(size=6, chars=string.ascii_uppercase+string.digits+string.ascii_lowercase):
	return random.choice(string.ascii_lowercase) + ''.join(random.choice(chars) for _ in range(size - 1))

def anticollision(path):
	#shutil.copy("challengers/"+path, "challengers/"+path+".bu")
	s = open("challengers/"+path).read()
	rep = path[::-1][2:][::-1]
	s = s.replace(rep, "@@@PLACEHOLDER@@@")
	r = re.findall(r"[\w]+.*?	.*?([_\w\d]+)\(.*?\)", s)
	for f in r:
		s = s.replace(f, id_gen(12))
	s = s.replace("@@@PLACEHOLDER@@@", rep)
	open("challengers/"+path, "w+").write(s)
	pass

def main():
	scores = dict()
	files = os.listdir("./challengers")
	files = [f for f in files if f[::-1][:2] == 'c.']
	if not files:
		print 'no challengers'
	for c in files:
		anticollision(c)
	for c in files:
		for c2 in files:
			if c == c2:
				continue
			nam = c.split(".")[0]
			nam2 = c2.split(".")[0]
			#print nam, nam2
			f = open(MAIN).read()
			f = f.replace("p4_player1", nam)
			f = f.replace("p4_player2", nam2)
			nam = nam.replace("p4_getmove_", "")
			nam2 = nam2.replace("p4_getmove_", "")
			f = f.replace("Player1", nam)
			f = f.replace("Player2", nam2)
			try:
				scores[nam]
			except:
				scores[nam] = 0
			try:
				scores[nam2]
			except:
				scores[nam2] = 0
			#print scores
			print "\x1b[1m\x1b[32m>>> Matchup:\x1b[33m", nam, "\x1b[32mVs.\x1b[31m", nam2, "!\x1b[0m"
			open(MAIN_TMP, "w+").write(f)
			os.popen(COMPILE_L % (MAIN_TMP, c, c2))
			os.remove(MAIN_TMP)
			try:
				res = os.popen("./p4out 2> /dev/null").read()
			except:
				pass
			try:
				os.remove("./p4out")
			except:
				pass
			print res if res else "\x1b[1m\x1b[31mNo Contest\n\x1b[0m"
			#sc = re.findall(r"([\w]+): ([\d]+) \(.*?\)", res)
			try:
				winner = re.findall(r"Winner: ([\w]+) !", res)[0]
				scores[winner] = scores[winner] + 2
			except:
				try:
					scores[nam] = scores[nam] + 1
				except:
					pass
				try:
					scores[nam2] = scores[nam2] + 1
				except:
					pass
				pass
	scores = [(a, scores[a]) for a in scores]
	#print scores
	scores.sort(key=lambda tup: tup[1], reverse=True)
	#print scores
	print 'Ranking\n--------'
	for name, sc in scores:
		print "%-20s %5d" % (name, sc)

if __name__ == "__main__":
	main()
