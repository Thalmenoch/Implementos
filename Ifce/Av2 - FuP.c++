	#include <iostream>
	#include <string>
	#include <cstdlib>
	#include <ctime>

	using namespace std;
	int main()
	{	
		srand((int) time(0));
		char x[3][3];
		int l, c, a = 0, t = 0, placer, aux;
		// As variáveis a e t são de checagem 
		for(int i = 0; i < 3; i ++)
		{
			for(int j = 0; j < 3; j ++)
			{
				x[i][j] = ' ';
			}
		}

		cout << "Escolha 1 para o multiplayer e Escolha 2 para o singleplayer !" << endl;
		cout << "Qual sua escolha ? ";
		cin >> placer;

		if(placer == 1){	
			while(true)// singleplayer
			{
				do{
				
				cout << "Escolha a linha do jogador X (1, 2 ou 3): ";
				cin >> l;
				
				cout << "Escolha a coluna do jogador X (1, 2 ou 3): ";
				cin >> c;
				
				if(l > 3 || l < 1)
					cout << "Valor de linha invalido !" << endl;
				if(c > 3 || c < 1)
					cout << "Valor de coluna invalido !" << endl;	 

				cout << endl;	

				}while(l > 3 || l < 1 || c > 3 || c < 1 || x[l - 1][c - 1] != ' ');

				l--;c--;

				x[l][c] = 'X';


			 	for(int i = 0; i < 3; i ++)
		    	{
					for(int j = 0; j < 3; j++)
					{	
						cout << "| " << x[i][j] << " ";
					}
		  			cout << "|" << endl;
		    	
		    		if(i < 2)
		    			cout << "+---+---+---+" << endl;
		    	}

		   		for(int i = 0; i < 3; i ++)
		    	{	
		    		if(x[i][0] == 'X' && x[i][1] == 'X' && x[i][2] == 'X')
		    			a++;	
		    	}
	 		
	 			for(int i = 0; i < 3; i ++)
		    	{	
		    		if(x[0][i] == 'X' && x[1][i] == 'X' && x[2][i] == 'X')
		    			a++;	
		    	}
		    
		    	if(a == 1)
		    		break;
		    	if(x[0][0] == 'X' && x[1][1] == 'X' && x[2][2] == 'X')
		    		break;
		    	if(x[0][2] == 'X' && x[1][1] == 'X' && x[2][0] == 'X')
		    		break;
		    	t ++;
		    	
		    	if(t == 9)
		    		break;
		    	
		    	// Aqui é a parte do O

		    	do{
				cout << "Escolha a linha do jogador O (1, 2 ou 3): ";
				cin >> l;
				
				cout << "Escolha a coluna do jogador O (1, 2 ou 3): ";
				cin >> c;
				
				if(l > 3 || l < 1)
					cout << "Valor de linha invalido !" << endl;
				if(c > 3 || c < 1)
					cout << "Valor de coluna invalido !" << endl;	 
				
				cout << endl;	

				}while(l > 3 || l < 1 || c > 3 || c < 1 || x[l - 1][c - 1] != ' ' );

				l --; c --;

				x[l][c] = 'O';


			 	for(int i = 0; i < 3; i ++)
		    	{
					for(int j = 0; j < 3; j++)
					{	
						cout << "| " << x[i][j] << " ";
					}
		  				cout << "|" << endl;
		    	
		    		if(i < 2)
		    			cout << "+---+---+---+" << endl;
		    	}
			
				for(int i = 0; i < 3; i ++)
		    	{	
		    		if(x[i][0] == 'O' && x[i][1] == 'O' && x[i][2] == 'O')
		    			a++;	
		    	}
		    
		    	for(int i = 0; i < 3; i ++)
		    	{	
		    		if(x[0][i] == 'O' && x[1][i] == 'O' && x[2][i] == 'O')
		    			a++;	
		    	}
		    
		    	if(a == 1)
		    		break;
		    	if(x[0][0] == 'O' && x[1][1] == 'O' && x[2][2] == 'O')
		    		break;
		    	if(x[0][2] == 'O' && x[1][1] == 'O' && x[2][0] == 'O')
		    		break;    
				t ++;
			}
		}	
		
		if(placer == 2)//multiplayer
		{
			cout << "Nesse jogo vc será o O !" << endl;;
			while(true)
			{
				if(t == 0)
				{	
					aux = (rand() % 2);
					aux = 0;
					//aux = 1 -_-
					if(aux == 0)
						x[0][0] = 'X';
					if(aux == 1)
						x[1][1] = 'X';
				}
				if(t == 2)
				{
					if(aux == 0)
					{
						if(x[1][1] != 'O')
							x[1][1] = 'X';
						else
							x[2][0] = 'X';
					}
				
					if(aux == 1)
					{
						if(x[0][0] == 'O')
							x[2][0] = 'X';
						
						if(x[1][0] == 'O')
							x[0][0] = 'X';
						
						if(x[2][0] == 'O')
							x[0][0] = 'X';
						
						if(x[0][1] == 'O')
							x[0][0] = 'X';
						
						if(x[0][2] == 'O')
							x[2][2] = 'X';
						
						if(x[1][2] == 'O')
							x[2][2] = 'X';
						
						if(x[2][1] == 'O')
							x[2][0] = 'X';
						
						if(x[2][2] == 'O')
							x[0][2] = 'X';
					}
				}
				if(t == 4)
				{
					if(aux == 0)
					{
						if(x[1][1] == 'X' && x[2][2] != 'O')
							x[2][2] = 'X';
						else
						{
							if(x[2][0] == 'X' && x[1][0] != 'O')
								x[1][0] ='X';
							else
							{	if(x[2][0] == 'X' && x[1][2] != 'O')
									x[1][2] = 'X';
							}
							
							if(x[1][1] == 'X' && x[2][2] =='O' && x[0][2] == 'O')
							{	
								x[1][2] = 'X';
							}else
							{
								if(x[1][1] == 'X' && x[2][2] == 'O' && x[2][0] == 'O')
									x[2][1] = 'X';
								else{
									if(x[1][1] == 'X' && x[2][2] == 'O' && (x[0][1] == 'O' || x[1][0] == 'O' 
										|| x[2][1] == 'O') && x[2][0] != 'O')
										x[2][0] = 'X';
									else{
										if(x[1][1] == 'X' && x[2][2] == 'O' && x[1][2] == 'O' && x[0][2] != 'O')
											x[0][2] = 'X';
									}
								}
							}
						}
					}
					
					if(aux == 1)
					{
						if(x[0][0] == 'O' && x[2][0] == 'X' && x[0][2] != 'O')
							x[0][2] = 'X';
						else
						{
							if(x[0][0] == 'O' && x[2][0] == 'X' && x[0][2] == 'O')
								x[0][1] = 'X';
						}

						if(x[1][0] == 'O' && x[0][0] == 'X' && x[2][2] != 'O')
							x[2][2] = 'X';
						else
						{
							if(x[1][0] == 'O' && x[0][0] == 'X' && x[2][2] == 'O')
								x[0][2] = 'X';
						}
						
						if(x[2][0] == 'O' && x[0][0] == 'X' && x[2][2] != 'O')
							x[2][2] = 'X';
						else
						{
							if(x[2][0] == 'O' && x[0][0] == 'X' && x[2][2] == 'O')
								x[2][1] = 'X';
						}
						
						if(x[0][1] == 'O' && x[0][0] == 'X' && x[2][2] != 'O')
							x[2][2] = 'X';
						else
						{
							if(x[0][1] == 'O' && x[0][0] == 'X' && x[2][2] == 'O')
								x[2][0] = 'X';
						}
						
						if(x[0][2] =='O' && x[2][2] =='X' && x[0][0] != 'O')
							x[0][0] = 'X';
						else
						{
							if(x[0][2] =='O' && x[2][2] =='X' && x[0][2] == 'O')	
								x[0][1] = 'X';
						}
						
						if(x[1][2] == 'O' && x[2][2] == 'X' && x[0][0] != 'O')
							x[0][0] = 'X';
						else
						{
							if(x[1][2] == 'O' && x[2][2] == 'X' && x[0][0] == 'O')
								x[2][0] = 'X';
						}
						
						if(x[2][1] == 'O' && x[2][0] == 'X' && x[0][2] != 'O')
							x[0][2] = 'X';
						else
						{
							if(x[2][1] == 'O' && x[2][0] == 'X' && x[0][2] == 'O')
								x[0][0] = 'X';
						}
						
						if(x[2][2] == 'O' && x[0][2] == 'X' && x[2][0] != 'O')
							x[2][0] = 'X';
						else
						{
							if(x[2][2] == 'O' && x[0][2] == 'X' && x[2][0] == 'O')
								x[2][1] = 'X';
						}
					}
				}
				if(t == 6)
				{
					if(aux == 0)
					{
						if(x[1][1] == 'O' && x[1][0] == 'O' && x[1][2] == 'X' && x[0][1] == 'O')
							x[2][1] = 'X';
						else{
							if(x[1][1] == 'O' && x[1][0] == 'O' && x[1][2] == 'X' && x[2][1] == 'O')
								x[0][1] = 'X';
							else{
								if(x[1][1] == 'O' && x[1][0] == 'O' && x[1][2] == 'X' && x[0][2] != 'O')
									x[0][2] = 'X';
								else{
									if(x[1][1] == 'O' && x[1][0] == 'O' && x[1][2] == 'X' && x[0][2] == 'O')
										x[2][2] = 'X';
								}
							}
							if(x[1][1] == 'X' && x[2][2] == 'O' && x[0][2] == 'O' && x[1][2] == 'X' && x[1][0] != 'O')
								x[1][0] = 'X';
							else{
								if(x[1][1] == 'X' && x[2][2] == 'O' && x[0][2] == 'O' && x[1][2] == 'X' && x[1][0] == 'O')
									x[2][1] = 'X';
							}	
							if(x[1][1] == 'X' && x[2][2] == 'O' && x[2][0] == 'O' && x[2][1] =='X' && x[0][1] != 'O')
								x[0][1] = 'X';
							else{
								if(x[1][1] == 'X' && x[2][2] == 'O' && x[2][0] == 'O' && x[2][1] =='X' && x[0][1] == 'O')
									x[1][2] = 'X';
							}
							if(x[1][1] == 'X' && x[2][2] == 'O' && x[2][0] == 'X' && (x[0][1] == 'O' 
								|| x[1][0] == 'O' || x[2][1] == 'O') && x[0][2] != 'O')
								x[0][2] = 'X';
							else{
								if(x[1][1] == 'X' && x[2][2] == 'O' && x[0][2] == 'X' && x[1][2] == 'O' && x[2][0] != 'O')
									x[2][0] = 'X';
								else{
									if(x[1][1] == 'X' && x[2][2] == 'O' && x[2][0] == 'X' && (x[0][1] == 'O' 
								 || x[2][1] == 'O') && x[0][2] == 'O')
										x[1][0] = 'X';
									else{
										if(x[1][1] == 'X' && x[2][2] == 'O' && x[1][0] == 'O' && x[2][0] == 'X' && x[0][2] != 'O')
											x[0][2] = 'X';
											else{
												if(x[1][1] == 'X' && x[2][2] == 'O' && x[1][0] == 'O' && x[2][0] == 'X' && x[0][2] == 'O')
													x[1][2] = 'X';
												else{
													if(x[1][1] == 'X' && x[2][2] == 'O' && x[0][2] == 'X' && 
														x[1][2] == 'O' && x[2][0] == 'O')
														x[0][1] = 'X';
												}
										}
									}	
								}
							}
						}
					}		
					
					if(aux == 1)
					{
						if(x[2][2] == 'O' && x[0][2] == 'X' && x[2][0] != 'O')
							x[2][0] = 'X';
						else
						{
							if(x[2][2] == 'O' && x[0][2] == 'X' && x[2][0] == 'O')
								x[0][1] = 'X';
						}
						
						if(x[0][1] == 'O' && x[2][0] == 'X' && x[0][2] != 'X')
							x[0][2] = 'X';
						else
						{
							if(x[0][1] == 'O' && x[2][0] == 'X' && x[0][2] == 'X')
								x[1][0] = 'X';
						}

						if(x[1][2] == 'O' && x[2][0] == 'X' && x[0][2] != 'O')
							x[0][2] = 'X';
						else
						{
							if(x[1][2] == 'O' && x[2][0] == 'X' && x[0][2] == 'O')
								x[2][1] = 'X';
						}

						if(x[2][1] == 'O' && x[0][0] == 'X' && x[2][2] != 'O')
							x[2][2] = 'X';
						else
						{
							if(x[2][1] == 'O' && x[0][0] == 'X' && x[2][2] == 'O')
								x[1][0] = 'X';
						}
						
						if(x[0][0] == 'O' && x[2][0] == 'O' && x[0][1] != 'X')
							x[0][1] = 'X';

						if(x[2][0] == 'O' && x[2][2] == 'O' && x[2][1] != 'X')
							x[2][1] = 'X';

						if(x[0][0] == 'O' && x[0][2] == 'O' && x[0][1] != 'X')
							x[1][0] = 'X';

						if(x[0][2] == 'O' && x[2][2] == 'O' && x[1][2] != 'X')
							x[1][2] = 'X';
					}
				}
				if(t == 8)	
				{	
					if(aux == 0)
					{	
						if(x[1][1] == 'O' && x[0][1] == 'O' && x[2][1] == 'O' && x[0][1] == 'X' && x[0][2] != 'O')
							x[0][2] = 'X';
						else{
							if(x[1][1] == 'O' && x[0][1] == 'O' && x[0][1] == 'O' && x[2][1] == 'X' && x[2][2] != 'O')
								x[2][2] = 'X';
							else{
								if(x[1][1] == 'O' && x[0][1] == 'O' && x[2][1] == 'O' && x[0][1] == 'X' && x[0][2] == 'O'){
									x[2][2] = 'X';
								}
								else
									if(x[1][1] == 'O' && x[0][1] == 'O' && x[0][1] == 'O' 
										&& x[2][1] == 'X' && x[2][2] == 'O')
										x[0][2] = 'X';
									else{
										if(x[1][1] == 'O' && x[1][0] == 'O' && x[1][2] == 'X' && x[2][1] == 'O' && x[0][1] == 'X' && x[2][2] == 'O' && x[0][2] != 'O')
											x[0][2] = 'X';
										else{
											if(x[1][1] == 'O' && x[1][0] == 'O' && x[1][2] == 'X' && x[2][1] == 'O' && x[0][1] == 'X' && x[0][2] == 'O' && x[2][2] != 'O')
												x[2][2] = 'X';
										}
									}
							}
						}
						if(x[1][1] == 'X' && x[2][2] == 'O' && x[0][2] == 'O' && x[2][0] != 'O')
							x[2][0] = 'X';
							else{
								if(x[1][1] == 'X' && x[2][2] == 'O' && x[2][0] == 'O' && x[0][2] != 'O')
									x[0][2] = 'X';
							}
						if(x[1][1] == 'O' && x[1][0] == 'O' && x[1][2] == 'X' && x[0][2] == 'X' && x[0][1] != 'O')
							x[0][1] = 'X';
						else{
							if(x[1][1] == 'O' && x[1][0] == 'O' && x[1][2] == 'X' && x[0][2] == 'X' && x[0][1] == 'O')
								x[2][1] = 'X';
								else{
									if(x[1][1] == 'X' && x[2][2] == 'O' && x[1][0] == 'O' && x[2][0] == 'X' && x[0][2] == 'O' && x[1][2] == 'X' && x[0][1] == 'O')
										x[2][1] = 'X';
										else{
											if(x[1][1] == 'X' && x[2][2] == 'O' && x[1][0] == 'O' && x[2][0] == 'X' && x[0][2] == 'O' && x[1][2] == 'X' && x[2][1] == 'O')
											x[0][1] = 'X';
										}

								}
						}
						if(x[1][1] == 'O' && x[1][0] == 'O' && x[1][2] == 'X' && x[2][2] == 'X' && x[2][1] != 'O')
							x[2][1] = 'X';
						else{
							if(x[1][1] == 'O' && x[1][0] == 'O' && x[1][2] == 'X' && x[2][2] == 'X' && x[2][1] == 'O')
								x[0][1] = 'X';
						}
					}
				}
					
				for(int i = 0; i < 3; i ++)
		    	{
					for(int j = 0; j < 3; j++)
					{	
						cout << "| " << x[i][j] << " ";
					}
		  				cout << "|" << endl;
		    	
		    		if(i < 2)
		    			cout << "+---+---+---+" << endl;
		    	}

		    	for(int i = 0; i < 3; i ++)
		    	{	
		    		if(x[i][0] == 'X' && x[i][1] == 'X' && x[i][2] == 'X')
		    			a++;	
		    	}
	 		
	 			for(int i = 0; i < 3; i ++)
		    	{	
		    		if(x[0][i] == 'X' && x[1][i] == 'X' && x[2][i] == 'X')
		    			a++;	
		    	}
		    
		    	if(a == 1)
		    		break;
		    	if(x[0][0] == 'X' && x[1][1] == 'X' && x[2][2] == 'X')
		    		break;
		    	if(x[0][2] == 'X' && x[1][1] == 'X' && x[2][0] == 'X')
		    		break;
		    	t ++;
		    	
		    	if(t == 9)
		    		break;
		    	system("pause");
		    	// Aqui começa a parte do O
		    	do{
					cout << "Escolha a linha do O: ";
					cin >> l;
					cout << "Escolha a coluna do O: ";
					cin >> c;

				if(l > 3 || l < 1)
					cout << "Valor de linha invalido !" << endl;
				if(c > 3 || c < 1)
					cout << "Valor de coluna invalido !" << endl;	 
				
				cout << endl;	
				
				}while(l > 3 || l < 1 || c > 3 || c < 1 || x[l - 1][c - 1] != ' ');
				
				l--; c--;
				x[l][c] = 'O';

		    	for(int i = 0; i < 3; i ++)
		    	{	
		    		if(x[i][0] == 'O' && x[i][1] == 'O' && x[i][2] == 'O')
		    			a++;	
		    	}
		    
		    	for(int i = 0; i < 3; i ++)
		    	{	
		    		if(x[0][i] == 'O' && x[1][i] == 'O' && x[2][i] == 'O')
		    			a++;	
		    	}
		    
		    	if(a == 1)
		    		break;
		    	if(x[0][0] == 'O' && x[1][1] == 'O' && x[2][2] == 'O')
		    		break;
		    	if(x[0][2] == 'O' && x[1][1] == 'O' && x[2][0] == 'O')
		    		break;    
				t ++;
			}
		}
		if(placer == 1 || placer == 2){
		cout << "GG !" << endl;
		}else{
			cout<< "Modo de jogo desconhecido !" << endl;
		}
		system("pause");
		return 0;
	}