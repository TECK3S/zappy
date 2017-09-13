print("Start the script");

eState = 
   {
   L1 = 1,
   L2 = 2,
   L3 = 3,
   L4 = 4,
   L5 = 5,
   L6 = 6,
   L7 = 7,
   L8 = 8,
   STATE_ERROR
};

eAction =
   {
   ACT_INC = 1,
   ACT_TOP = 2,
   ACT_ERROR = 3
};


StateTable =
   {
   {eState.L2, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR},
   {eState.STATE_ERROR, eState.L3, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR},
   {eState.STATE_ERROR, eState.STATE_ERROR, eState.L4, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR},
   {eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.L5, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR},
   {eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.L6, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR},
   {eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.L7, eState.STATE_ERROR, eState.STATE_ERROR},
   {eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.L8, eState.STATE_ERROR},
   {eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR, eState.STATE_ERROR}
  };

ActionTable =
   {
   {eAction.INC, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR},
   {eAction.ACT_ERROR, eAction.INC, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR},
   {eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.INC, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR},
   {eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.IINC, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR},
   {eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.INC, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR},
   {eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.INC, eAction.ACT_ERROR, eAction.ACT_ERROR},
   {eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.ACT_ERROR, eAction.INC, eAction.ACT_ERROR},
   {       eAction.TOP,        eAction.TOP,       eAction.TOP,     eAction.TOP,       eAction.TOP,       eAction.TOP,    eAction.TOP,    eAction.TOP   }
};

CommandTab = 
   {
   ahead = "avance\n",
   right = "droite\n",
   left = "gauche\n",
   see = "voir\n",
   inventory = "inventaire\n",
   take = "prend\n",
   set = "pose\n",
   expulse = "expulse\n",
   broad = "broadcast\n" ,
   inc = "incantation\n",
   fork = "fork\n", 
   connect = "connect_nbr\n",
   team = "equipe\n"
};

incantationTable =
   {
   {player = 1, linemate = 1, deraumere = 0, sibur = 0, mendiane = 0, phiras = 0, thystame = 0},
   {player = 2, linemate = 1, deraumere = 1, sibur = 1, mendiane = 0, phiras = 0, thystame = 0},
   {player = 2, linemate = 2, deraumere = 0, sibur = 1, mendiane = 0, phiras = 2, thystame = 0},
   {player = 4, linemate = 1, deraumere = 1, sibur = 2, mendiane = 0, phiras = 1, thystame = 0},
   {player = 4, linemate = 1, deraumere = 2, sibur = 1, mendiane = 3, phiras = 0, thystame = 0},
   {player = 6, linemate = 1, deraumere = 2, sibur = 3, mendiane = 0, phiras = 1, thystame = 0},
   {player = 6, linemate = 2, deraumere = 2, sibur = 2, mendiane = 2, phiras = 2, thystame = 1},

}

answer = "KO";
--have_seen = 0;
--nbr_player = 0;

indexTable =
   {"nourriture",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"   
}

ressources = 
   {
   teamName = nil,
   level = 1,
   inventory = 
      {current = {nourriture = 0,
		  linemate = 0,
		  deraumere = 0,
		  sibur = 0,
		  meniane = 0,
		  phiras = 0,
		  thystame = 0},
       required = {player = incantationTable[1][player],
		  linemate = incantationTable[1][linemate],
		  deraumere = incantationTable[1][deraumere],
		  sibur = incantationTable[1][sibur],
		  mendiane = incantationTable[1][mendiane],
		  phiras = incantationTable[1][phiras],
		  thystame = incantationTable[1][thystame]
	       }
   },
   view = {},
   slot_available = 0,
   slot_total = 0,
}

class 'IA' (IARessources)

function IA:__init(name)
   IARessources.__init(self, name);
end

function IA:checkRessources()
   print("Checking");
--   IAMakeCheck();
end

function IA:start()
   printStart();
  -- ressources.teamName = self._teamName;
   --IASend(CommandTab.inventory);
end

WestCostIA = IA('West cost');

function printStart()
   print("Starting the game in " .. WestCostIA._teamName);
end

function updateState()
   ressources.required[player] = incantationTable[ressources.level][player];
   ressources.required[linemate] = incantationTable[ressources.level][linemate];
   ressources.required[deraumere] = incantationTable[ressources.level][deraumere];
   ressources.required[sibur] = incantationTable[ressources.level][sibur]
   ressources.required[mendiane] = incantationTable[ressources.level][mendiane];
   ressources.required[phiras] = incantationTable[ressources.level][phiras];
   ressources.required[thystame] = incantationTable[ressources.level][thystame];
end

level1 = function (n)
	    if (n ~= 1) then
	       IASend(CommandTab.expulse);
	    elseif (hasRessources() == 1) then
	       IASend(CommandTab.inc);
	       updateSate();
	    end
	 end

level2 = function (n)
	    
	 end

level3 = function (n)
	    
	 end

level4 = function (n)
	    
	 end

level5 = function (n)
	    
	 end

level6 = function (n)
	    
	 end

level7 = function (n)
	    
	 end

level8 = function (n)
	    
	 end

checkLevel = 
   {level1,
    level2,
    level3,
    level4,
    level5,
    level6,
    level7,
    level8
}


ahead = function ()
	   answer = WestCostIA._msg;
	end

right = function ()
	   answer = WestCostIA._msg;
	end

letft = function ()
	   answer = WestCostIA._msg;
	end

see = function ()
	 ressources.view = {};
	 local splitView = split(WestCosIA._msg, ",");
	 local i = 1;
	 while splitView[i] do
	    local s = split(splitView[i], " ");
	    ressources.view[i] = s;
	    i = i + 1;
	 end
	 local nbr_player = getNbrPLayer(ressources.view[1]);
	 chekLevel[ressources.level](nbr_player);
      end

inventory = function ()
	       local splitInventory = split(WestCostIA._msg, ",");
	       local i = 1;
	       while i <= 7 do
		  local j = string.find(splitInventory[i], ' ');
		  local s;
		  if (j == 1) then
		     s = split(string.sub(splitInventory[i], j + 1), " ");
		  else
		     s = split(splitInventory[i], " ");
		  end
		  ressources.current[indexTable[i]] = s[2];
		  i = i + 1
	       end
	       IASend(CommandTab.see);
	    end
   
take = function ()
	  answer = WestCostIA._msg;
       end

set = function ()
	 answer = WestCostIA._msg;
      end

broad = function ()
	   --------------
	end

inc = function ()
	 answer = WestCostIA._msg;
      end

fork = function ()
	  answer = WestCostIA._msg;
       end

connect_nbr = function ()
		 -----------
	      end

check =
   {
   ahead,
   right,
   left,
   see,
   inventory,
   take,
   set,
   broad,
   inc,
   fork,
   connect_nbr,
   team,
};

function IAMakeCheck()
   WestCostIA:checkMsg();
   check[WestCostIA._opcode]();
end

function IASend(m)
  WestCostIA:doNotify(m);
end

function getNbrPLayer(tab)
   local i = 1;
   while (tab[i] and tab[i] == "joueur") do
      i = i + 1;
   end
   return (i - 1);
end

function split(str, pat)
   local t = {}
   local fpat = "(.-)" .. pat
   local last_end = 1
   local s, e, cap = str:find(fpat, 1)
   while s do
      if s ~= 1 or cap ~= "" then
	 table.insert(t,cap)
      end
      last_end = e+1
      s, e, cap = str:find(fpat, last_end)
   end
   if last_end <= #str then
      cap = str:sub(last_end)
      table.insert(t, cap)
   end
   return t
end