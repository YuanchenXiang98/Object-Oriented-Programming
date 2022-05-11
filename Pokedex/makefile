pp = g++


all:test pokemons

PokeDex.o: PokeDex.cpp PokeDex.h

	$(pp) PokeDex.cpp PokeDex.h -o PokeDex.o

Grass.o: Grass.cpp Grass.h

	$(pp) Grass.cpp Grass.h -o Grass.o

Fire.o: Fire.cpp Fire.h

	$(pp) Fire.cpp Fire.h -o Grass.o

Water.o: Water.cpp Water.h

	$(pp) Water.cpp Water.h -o Water.o




input_function_test:IsChoosenValid.cpp IsChoiceValid.cpp IsAddValid.cpp IsClearValid.cpp IsIDValid.cpp IsDeleteValid.cpp IsTypeValid.cpp input_function_test.cpp

	$(pp) IsChoosenValid.cpp IsChoiceValid.cpp IsAddValid.cpp IsClearValid.cpp IsIDValid.cpp IsDeleteValid.cpp IsTypeValid.cpp input_function_test.cpp -o input_function_test


Player_test:IsClearValid.cpp IsDeleteValid.cpp IsAddValid.cpp IsIDValid.cpp IsTypeValid.cpp Grass.cpp Fire.cpp Water.cpp PokeDex.cpp Player.cpp Player_test.cpp

	$(pp) IsClearValid.cpp IsDeleteValid.cpp IsAddValid.cpp IsIDValid.cpp IsTypeValid.cpp Grass.cpp Fire.cpp Water.cpp PokeDex.cpp Player.cpp Player_test.cpp -o Player_test


Doctor_test:IsClearValid.cpp IsDeleteValid.cpp IsAddValid.cpp IsIDValid.cpp IsTypeValid.cpp Grass.cpp Fire.cpp Water.cpp PokeDex.cpp Doctor.cpp Doctor_test.cpp

	$(pp) IsClearValid.cpp IsDeleteValid.cpp IsAddValid.cpp IsIDValid.cpp IsTypeValid.cpp Grass.cpp Fire.cpp Water.cpp PokeDex.cpp Doctor.cpp Doctor_test.cpp -o Doctor_test


PokeDex_test:IsClearValid.cpp IsDeleteValid.cpp IsAddValid.cpp IsIDValid.cpp IsTypeValid.cpp Grass.cpp Fire.cpp Water.cpp PokeDex.cpp Player.cpp Doctor.cpp PokeDex_test.cpp

	$(pp) IsClearValid.cpp IsDeleteValid.cpp IsAddValid.cpp IsIDValid.cpp IsTypeValid.cpp Grass.cpp Fire.cpp Water.cpp PokeDex.cpp Player.cpp Doctor.cpp PokeDex_test.cpp -o PokeDex_test


test:input_function_test Player_test Doctor_test PokeDex_test

	./input_function_test < input01.txt

	./Player_test < input03.txt

	./Doctor_test < input04.txt

	./PokeDex_test < input02.txt


pokemons: Main.cpp Grass.cpp Fire.cpp Water.cpp PokeDex.cpp Doctor.cpp Player.cpp IsIDValid.cpp IsDeleteValid.cpp IsTypeValid.cpp IsChoiceValid.cpp IsChoosenValid.cpp IsClearValid.cpp IsAddValid.cpp

	$(pp) IsChoosenValid.cpp IsChoiceValid.cpp IsAddValid.cpp IsClearValid.cpp IsIDValid.cpp IsDeleteValid.cpp IsTypeValid.cpp Grass.cpp Fire.cpp Water.cpp PokeDex.cpp Doctor.cpp Player.cpp Main.cpp -o pokemons

	./pokemons

clean:

	rm -f *.o Race
