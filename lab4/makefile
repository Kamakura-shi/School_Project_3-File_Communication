EXECDIR = Debug
INCLUDES_PATH = includes
SRC_PATH = src

$(shell mkdir -p Debug)

all: $(EXECDIR)/client $(EXECDIR)/serveur

$(EXECDIR)/client : client.c $(SRC_PATH)/*.c $(INCLUDES_PATH)/*.h
		gcc -g -o $(EXECDIR)/client -I $(INCLUDES_PATH) client.c $(SRC_PATH)/*.c

$(EXECDIR)/serveur : serveur.c $(SRC_PATH)/*.c $(INCLUDES_PATH)/*.h
		gcc -g -o $(EXECDIR)/serveur -I $(INCLUDES_PATH) serveur.c $(SRC_PATH)/*.c

clean :
		rm -rf $(EXECDIR)