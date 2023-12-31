CREATE TABLE personagens(
  	nome VARCHAR(40) NOT NULL unique,
  	almas int NOT NULL,
  	classe varchar(40) check( classe = 'Warrior' or classe = 'Knight' or classe = 'Wanderer' or classe = 'Thief' or classe = 'Bandit' or classe = 'Hunter' or classe = 'Sorcerer' or classe = 'Pyromancer' or classe = 'Cleric' or classe = 'Deprived') NOT NULL,
  	hp int NOT NULL,
  	stamina int NOT NULL,
  	equip_load int NOT NULL,
  	item_discovery int NOT NULL,
  	attunment_slot int NOT NULL,
  	bleed_res int NOT NULL,
  	poison_res int NOT NULL,
  	curse_res int NOT NULL,
  	poise int NOT NULL,
  	nivel int NOT NULL,
  	vit int NOT NULL,
  	att int NOT NULL,
  	endu int NOT NULL,
  	str int NOT NULL,
  	dex int NOT NULL,
  	res int NOT NULL,
  	int int NOT NULL,
  	fth int NOT NULL,
  	hum int NOT NULL,
  	PRIMARY KEY (nome)
);
  
CREATE TABLE items (
  	nome varchar(40) NOT NULL UNIQUE,
  	descricao varchar (10000) NOT NULL,
  	PRIMARY KEY (nome)
);

CREATE TABLE entidades (
  	nome varchar(40) NOT NULL UNIQUE,
  	PRIMARY KEY (nome)
);

CREATE TABLE mapas (
  	nome VARCHAR(45) NOT NULL unique,
  	nome_boss VARCHAR(45) not NULL,
  	FOREIGN key (nome_boss) REFERENCES entidades (nome),
  	PRIMARY KEY (nome)
);

CREATE TABLE spells (
	nome_spell VARCHAR(45) NOT NULL UNIQUE,
  	categoria VARCHAR (45) CHECK ( categoria = 'Sorceries' or categoria = 'Pyromancies' or categoria = 'Miracles') NOT NULL,
  	usos int NOT NULL, 
  	slots int NOT NULL,
  	int_req int NOT NULL,
  	fht_req int NOT NULL,
  	tipo VARCHAR(45) NOT NULL,
  	FOREIGN KEY (nome_spell) REFERENCES items (nome) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE equipamentos (
  	nome_equipamento VARCHAR(45) NOT NULL UNIQUE,
  	categoria VARCHAR(45) NOT NULL ,
  	tipo_ataque VARCHAR(45) NOT NULL,
  	fis INT NOT NULL,
  	magi INT NOT NULL,
  	fire INT NOT NULL,
  	eletro INT NOT NULL,
  	crit INT NOT NULL,
   	fis_res DECIMAL NOT NULL,
  	magi_res DECIMAL NOT NULL,
  	fire_res DECIMAL NOT NULL,
  	eletro_res DECIMAL NOT NULL,
  	stabilidade INT NOT NULL,
  	durabilidade INT NOT NULL,
  	peso DECIMAL NOT NULL, 
  	str_bonus VARCHAR(1) NOT NULL,
  	dex_bonus VARCHAR(1) NOT NULL,
  	int_bonus VARCHAR(1) NOT NULL,
  	fht_bonus VARCHAR(1) NOT NULL,
  	str_req INT NOT NULL,
  	dex_req INT NOT NULL,
  	int_req INT NOT NULL,
  	fht_req INT NOT NULL,  
  	FOREIGN KEY (nome_equipamento) REFERENCES items (nome) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE armaduras (
  	nome_armadura VARCHAR(45) NOT NULL unique,
  	r_fis INT NOT NULL,
  	r_impacto INT NOT NULL,
  	r_corte INT NOT NULL,
  	r_perfurar INT NOT NULL,
 	r_magic INT NOT NULL,
  	r_fogo INT NOT NULL,
  	r_electro INT NOT NULL,
  	r_bleed DECIMAL NOT NULL,
  	r_poison DECIMAL NOT NULL,
  	r_curse DECIMAL NOT NULL,
  	durabilidade INT NOT NULL,
  	peso DECIMAL NOT NULL,
  	poise DECIMAL NOT NULL,
  	FOREIGN KEY (nome_armadura) REFERENCES items (nome) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE monstro (
  	nome_monstro VARCHAR(45) NOT NULL UNIQUE,
  	classe VARCHAR(45) NOT NULL,
  	r_fis VARCHAR(8) NOT NULL,
  	r_impacto VARCHAR(8) NOT NULL,
  	r_corte VARCHAR(8) NOT NULL,
  	r_perfurar VARCHAR(8) NOT NULL,
  	r_magic VARCHAR(8) NOT NULL,
  	r_fogo VARCHAR(8) NOT NULL,
  	r_electro VARCHAR(8) NOT NULL,
  	r_poison VARCHAR(1) NOT NULL,
  	r_toxic VARCHAR(1) NOT NULL,
  	r_bleed VARCHAR(1) NOT NULL,
	FOREIGN KEY (nome_monstro) REFERENCES entidades (nome) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE boss (
  	nome_boss VARCHAR(45) NOT NULL unique,
  	HP INT NOT NULL,
  	souls INT NOT NULL,
	FOREIGN KEY (nome_boss) REFERENCES entidades (nome) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE npcs (
  	nome_npc VARCHAR(45) NOT NULL unique,
	FOREIGN KEY (nome_npc) REFERENCES entidades (nome) ON DELETE CASCADE ON UPDATE CASCADE
);
  
CREATE TABLE inventario (
 	nome_item VARCHAR(45) not NULL,
  	nome_personagem VARCHAR(45) not NULL,
  	quantidade INT not NULL,
  	UNIQUE (nome_item, nome_personagem),
  	primary key (nome_item, nome_personagem),
  	foreign key (nome_item) references items (nome) on delete cascade on update cascade,
  	foreign key (nome_personagem) references personagens (nome) on delete cascade on update cascade
);

CREATE TABLE equipa (
  nome_item VARCHAR(45) NOT NULL,
  nome_personagem VARCHAR(45) NOT NULL,
  slot INT NOT NULL,
  UNIQUE (nome_personagem, slot),
  FOREIGN KEY (nome_item, nome_personagem) REFERENCES inventario (nome_item, nome_personagem) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE npc_vende_item (
  nome_npc VARCHAR(45) NOT NULL,
  nome_item VARCHAR(45) NOT NULL,
  preco VARCHAR(45) NOT NULL,
  FOREIGN KEY (nome_npc) REFERENCES entidades (nome) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (nome_item) REFERENCES items (nome) ON DELETE CASCADE ON UPDATE CASCADE
);
  
CREATE TABLE dropa (
  nome_entidade VARCHAR(45) NOT NULL,
  nome_item VARCHAR(45) NOT NULL,
  chance DECIMAL(4,2) NOT NULL,
  FOREIGN KEY (nome_entidade) REFERENCES entidades (nome) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (nome_item) REFERENCES items (nome) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE mapa_tem_item (
  nome_item VARCHAR(45) NOT NULL,
  nome_mapa VARCHAR(45) NOT NULL,
  lugar VARCHAR (45) NOT NULL,
  FOREIGN KEY (nome_item) REFERENCES items (nome) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (nome_mapa) REFERENCES mapas (nome) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE respawn (
  nome_personagem VARCHAR(45) NOT NULL,
  nome_mapa VARCHAR(45) NOT NULL,
  nivel_bonefire VARCHAR (45) NOT NULL,
  FOREIGN KEY (nome_personagem) REFERENCES personagens (nome) ON DELETE CASCADE ON UPDATE CASCADE,
  FOREIGN KEY (nome_mapa) REFERENCES mapas (nome) ON DELETE CASCADE ON UPDATE CASCADE
);