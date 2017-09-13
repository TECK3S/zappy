----------------------------------------------------------------------------
----------------------------- Variables Globales ---------------------------
----------------------------------------------------------------------------

-------------------------------- return values -----------------------------
OK = 2
KO = 3
SAME = 4
----------------------------------------------------------------------------

-------------------------------- struct ia --------------------------------
ia = {
   teamName = nil,
   currentState = 1,
   level = 0,
   inventory = {},
   view = {},
   way = {},
   selectedStone = nil,
   neededStones = {},
   caseToGo = 0,
   command = {op = 0, cmd = nil},
   response = {op = 0, msg = nil}
}
---------------------------------------------------------------------------

-------------------------- define commands opcode -------------------------
op_avance = 0x01;
op_droite = 0x02;
op_gauche = 0x03;
op_voir = 0x04;
op_inventaire = 0x05;
op_prend = 0x06;
op_pose = 0x07;
op_expulse = 0x08;
op_broadcast = 0x09;
op_incantation = 0x0A;
op_fork = 0x0B;
op_connect_nbr = 0x0C;
op_equipe = 0x0D;
---------------------------------------------------------------------------

--------------------------- define commands msg ---------------------------
avance = "avance\n"
droite = "droite\n"
gauche = "gauche\n"
voir = "voir\n"
inventaire = "inventaire\n"
prend = "prend" -- + object
pose = "pose" -- + object
expulse = "expulse\n"
broadast = "broadcast" -- + msg
incantation = "incantation\n"
fork = "fork\n"
connect_nbr = "connect_nbr\n"
equipe = "equipe\n"
---------------------------------------------------------------------------
stop = "stop"
---------------------------------------------------------------------------

----------------------------- tableau command -----------------------------
-- op -- msg
commandTab =
   {
   {op_avance, avance},
   {op_droite, droite},
   {op_gauche, gauche},
   {op_voir, voir},
   {op_inventaire, inventaire},
   {op_prend, prend}, -- + object
   {op_pose, pose}, -- + object
   {op_expulse, expulse},
   {op_broadast, broadcast}, -- + msg
   {op_incantation, incantation},
   {op_fork, fork},
   {op_connect_nbr, connect_nbr},
   {op_equipe, equipe},
};
---------------------------------------------------------------------------


----------------------------- define objects ------------------------------
nourriture = "nourriture"
linemate = "linemate"
deraumere = "deraumere"
sibur = "sibur"
mandiane = "mandiane"
phiras = "phiras"
thystame = "thystame"
---------------------------------------------------------------------------

--------------------------- tableau nom incantations ----------------------
incantationTableName =  {"nbPlayer", "linemate", "deraumere", "sibur", "mandiane", "phiras", "thystame"}
---------------------------------------------------------------------------

-- tableau indiquant les objets necessaires pour incatation selon niveau --
incantationTable ={
   {"1", "1", "0", "0", "0", "0", "0"},
   {"2", "1", "1", "1", "0", "0", "0"},
   {"2", "2", "0", "1", "0", "2", "0"},
   {"4", "1", "2", "1", "0", "1", "0"},
   {"4", "1", "2", "1", "3", "0", "0"},
   {"6", "1", "2", "3", "0", "1", "0"},
   {"6", "2", "2", "2", "2", "2", "1"}
}
---------------------------------------------------------------------------

-- incantationTable ={
--    {1, 1, 0, 0, 0, 0, 0},
--    {2, 1, 1, 1, 0, 0, 0},
--    {2, 2, 0, 1, 0, 2, 0},
--    {4, 1, 2, 1, 0, 1, 0},
--    {4, 1, 2, 1, 3, 0, 0},
--    {6, 1, 2, 3, 0, 1, 0},
--    {6, 2, 2, 2, 2, 2, 1}
-- }

---------------------------------------------------------------------------
---------------------------- INTERFACE FUCNTIONS --------------------------
---------------------------------------------------------------------------

function	ClientIA:start() -- CLientIA:startLua()
   print ("**** in lua start")
   self:analyseCurrentState() -- self:
end

function	ClientIA:analyseCurrentState() -- CLientIA:analyseCurrentState()
   print ("**** in analyseCurrentState")
   --   print("currentState = "..ia.currentState)
   --   print(tabState[ia.currentState][1])

   local rep = tabState[ia.currentState][2]()
   print ("rep = "..rep)
   if rep == SAME then
      self:sendCommandLua() -- self:sendCommand()
      return
   else
      jumToState(tabChangeState[ia.currentState][ret])
      return -- la boucle du CORE sera sensee relancer analyseCurrentState()
   end
end

function	ClientIA:analyseResponse() -- CLientIA:analyseResponse()
   print ("**** in analyseResponse")
   if ia.response.msg == nil then
      print (" *** ananlyseResponse *** ERROR => response.msg = NULL")
      self:sendCommand()
      return --
   else
      if ia.response.op ~= ia.command.op then
	 if ia.response.op == op_broadcast then
	    local ret = analyseBroadcast()
	    jumpToState(ret)
	 end
      else
	 if ia.response.op == op_inventaire then
	    getInventoryTab(ia.reponse.msg)
	    setResponse(0, nil)
	 else if ia.response.op == op_voir then
	       getViewTab(ia.reponse.msg)
	       setResponse(0, nil)
	    end
	 end
      end
      self:analyseCurrentState()
   end
end

function	ClientIA:sendCommandLua()
   print ("**** in sendCommandLua")
   if ia.command.cmd == nil then
      print ("***** ERROR => ia.command")
      analyseCurrentState() ----------- self:
   else
      print ("**** ia.command.cmd is not nul = "..ia.command.cmd)
      self:setCommand(ia.command.op, ia.command.cmd)	-- c++
      self:sendCommand()				-- c++
   end
--send to server
end

function	ClientIA:setResponse(op, msg) -- depuis c++ ClientIA:setResponse(op, msg)
   print ("**** in setResponse")
   ia.response.op = op
   ia.response.msg = msg
end

function	ClientIA:catchReponse()
   print ("**** in catchReponse")
   -- setResponse(self:getOPResponse(), self:getMsgReponse())
   analyseResponse() -- self:
end

--- ///////////// TO DO
function	analyseBroadcast()
   return ia.currentState -- to modify
end
--//////////////

function	jumpToState(state)
   ia.currentState = state
end

---------------------------------------------------------------------------
---------------------------- State functions ------------------------------
---------------------------------------------------------------------------

--------------------------------- Food ------------------------------------
-- Function needFood
-- parameters: none
-- require: inventory
-- return: OK -- KO -- SAME
needFood = function () -- inventory
	      print ("**** in need food")
	      if ia.inventory[1] ~= nil then ------------------------------------goooooood
		 print ("**** inventory is not empty")
		 if getQtyObject(ia.invetory, "nourriture") < 10 --/////////// a revior
		 then
		    print ("**** return ok")
		    return OK
		 else
		    print ("**** return ko")
		    return KO
		 end
		 print ("**** return nothing")
	      else
		 print ("**** needFood => inventory is empty")
		 setCommand(op_inventaire, inventaire)----
		 return SAME
	      end
	   end

seeFood = function () -- tabView
	     return seeObject("nourriture")
	  end

goToFood = function ()
	      return goToCase()
	   end

takeFood = function ()
	      return takeObject("nourriture")
	   end

putDownFood = function ()
		 return putDownObject("nourriture")
	      end

broadcastFood = function () --///////// a revoir
		   return broadcastMsg("nourriture\n")
		end

turnToSeeFood = function ()
		   return turnToSeeFood("nourriture")
		end
---------------------------------------------------------------------------


------------------------------- Stone -------------------------------------
-- Function needStones
-- parameters: none
-- require: inventory
-- return: OK -- KO -- SAME
needStones = function ()
		local i = 1
		local y = 0
		ia.neededStones = {}
		if ia.inventory then
		   while ia.inventory[i] do
		      if ia.inventory[i][1] ~= "nourriture"
		      then
			 if ia.inventory[i][2] < ia.inventory[i][3]
			 then
			    y = y + 1
			    ia.neededStones[y] = ia.inventory[i][1]
			 end
		      end
		      i = i + 1
		   end
		else
		   setCommand(op_inventaire, inventaire)-----
		   return SAME
		end
		if ia.neededStones and y > 0 then
		   return OK
		else
		   return KO
		end
	     end

-- Fonction seeStones
-- parameters: none
-- require: inventory
-- return: OK -- KO -- SAME
-- object: string
seeStones = function ()	-- (tabView, object)
	       local ret
	       if ia.neededStone then
		  for i = 1, ia.neededStones[i] do
		     ret = seeObject(tabView, ia.neededStones[i])
		     if ret == OK or ret == SAME then -- OK et SAME
			if ret == OK then
			   ia.selectedStone = ia.neededStones[i]
			end
			return ret
		     end
		  end
		  ia.selectedStone = nil
		  return KO
	       else
		  setCommand(op_inventaire, inventaire) --
		  return SAME
	       end
	    end

goToStone = function ()
	      return goToCase()
	   end

takeStone = function ()
	      return takeObject(ia.selectedStone)
	   end

putDownStone = function (stone)
		 return putDownObject(stone)
	      end

broadcastStone = function () --///////// a revoir
		    return broadcastMsg(ia.selectedStone) -- + "\n")
		 end

turnToSeeStone = function () --/////////// a ameliorer
		   return turnToSeeFood(ia.selectedStone)
		end
---------------------------------------------------------------------------


------------------------------ People -------------------------------------
-- Fonction needmorepeople
-- parametres:
-- level: int
-- return: bool
needMorePeople = function ()
		    if (nbPeopleSameLevelOnCase) >= incantationTable[ia.level][1]
		    then
		       return OK
		    end
		    return KO
		 end

goToPeople = function (way)
		return goToCase(way)
	     end
---------------------------------------------------------------------------

----------------------------- tableau d'etats -----------------------------
tabState = {
   {1, needFood},
   {2, seeFood},
   {3, goToFood},
   {4, takeFood},
   {5, putDownFood},
   {6, broadcastFood},
   {7, turnToSeeFood},
   {8, needStone},
   {9, seeStones},
   {10, goToStone},
   {11, takeStone},
   {12, putDownStone},
   {13, broadcastStone},
   {14, turnToSeeStone},
   {15, needPoeple},
   {16, broadcastPeople},
   {17, seePoeple},
   {18, goTopeople},
   {17, incantion}
}
---------------------------------------------------------------------------


--------------------------- tableau de transitions ------------------------
-- numState -- state for OK -- state for KO -- same state
tabChangeState = {
   {1, 8, 2, 1},
   {2, 3, 5, 2},
   {3, 4, 2, 3},
   {4, 1, 2, 4},
   {5, 3, 7, 5},
   {6, 6, 6, 6},--a revoir
   {7, 2, 8, 7},
   {8, 12, 9, 8},
   {9, 10, 13, 9},
   {10, 11, 9, 10},
   {11, 1, 9, 11},
   {12, 12, 12, 12}, -- a revoir
   {13, 10, 14, 13},
   {14, 9, 9, 14},
   {15, 19, 16, 15},
   {16, 17, 17, 16},
   {17, 18, 16, 17},
   {18, 17, 17, 18},
   {19, 1, 1, 19}
}
---------------------------------------------------------------------------

---------------------------------------------------------------------------
------------------------------ TOOLS FUNCTIONS ----------------------------
---------------------------------------------------------------------------

---------------------------------------------------------------------------
------------------------------ ANALYSE IMVENTORY
---------------------------------------------------------------------------

-- Fonction getInventoryTab
-- parametres:
-- vision: string
-- return: tab[][]
function        getInventoryTab(inventory)
   ia.inventory = {}
   local splitInventory = split(inventory, ",")
   local i = 1
   local y = 2
   while splitInventory[i] do
      local s = split(splitInventory[i], " ")
      ia.inventory[i] = s
      i = i + 1
   end

   -- on indique le nombre de pierres requises pour le niveau
   i = 1
   while ia.inventory[i] do
      y = 2
      while incantationTableName[y] do
         if ia.inventory[i][1] == incantationTableName[y]
         then
            ia.inventory[i][3] = incantationTable[level][y]
         end
         y = y + 1
      end
      i = i + 1
   end
end


function	findOpcode(cmd)
   local i = 1
   while commandTab[i] do
      if commandTab[i][2] == cmd then
	 return commandTab[i][1]
      end
      i = i + 1
   end
   return 0
end

---------------------------------------------------------------------------
------------------------------ ANALYSE VIEW
---------------------------------------------------------------------------

-- Fonction getViewTab
-- parse la view sous forme de tableau
-- parametres:
-- view: string
-- return: OK -- KO
function	getViewTab(view)
   ia.view = {}
   if view[1] == '{' then
      strsub(s, 1)
      local b = strfind(s, '}')
      s = strsub(s, 1, b-1) .. strsub(s, b+1)
   end
   local splitView = split(view, ",")
   local i = 1
   while splitView[i] do
      local s = split(splitView[i], " ")
      ia.view[i] = s
      i = i + 1
   end
   if ia.view then
      return OK
   else
      return
      KO
   end
end

---------------------------------------------------------------------------
------------------------------ MOVE
---------------------------------------------------------------------------

-- function getWayToCAse
-- parameters:
-- case: indice
function	getWayToCAse(case)
   ia.way = {}
   local w = 0 -- way
   local i = 1 -- indice
   local niv = 0
   while i ~= case do
      if i < case and (i + niv) < case then -- on est pas au bon niveau
	 if i == 1 and niv == 0 then
	    i = 1 * 2 + i
	 else
	    i = niv * 2 + i
	 end
	 niv = niv + 1
	 w = w + 1
	 ia.way[w] = avance
      else
	 if i < case and (i + niv) >= case then -- on est au bon niveau => droite
	    ia.way[w] = droite
	    while i < case do
	       i = i + 1
	       w = w + 1
	       ia.way[w] = avance
	    end
	 else
	    if i > case and (i - niv) >= case then -- on est au bon niveau => gauche
	       ia.way[w] = gauche
	       while i > case do
		  i = i - 1
		  w = w + 1
		  ia.way[w] = avance
	       end
	    end
	 end
      end
   end
   if i == case then
      ia.way[w + 1] = stop
      return OK
   end
   return KO
end

function	goToCase()
   if ia.way[1] then
      if ia.way[1] == stop
      then
	 ia.way = {} -- reinitialie
	 return OK
      else
	 local op = findOpcode(way[1])
	 if op ~= 0 then
	    setCommand(op, way[1])
	    table.remove(way, 1)
	    return SAME
	 else
	    print ("**** goToCase => op didn't found", way[1])
	    ia.way = {} -- reinitialie
	    return KO
	 end
      end
   else
      return KO
   end
end

----------------------------------------------------------------------------
------------------------------ SETTER GETTER
----------------------------------------------------------------------------

function		setCommand(op, cmd)
   ia.command.op = op
   ia.command.cmd = cmd
end

function		setResponse(op, msg) -- depuis c++ ClientIA:setResponse(op, msg)
   ia.response.op = op
   ia.response.msg = msg
end

----------------------------------------------------------------------------
------------------------------ SEARCH OBJECTS
----------------------------------------------------------------------------

-- Function get_qty_object
-- parameters:
-- string: object
-- require: inventory
-- return the qty est a envoye
function	getQtyObject(object)
   local i = 1
   while inventory[i] do
      print (i)
      print (inventory[i])
      if inventory[i][1] == object then
	 return inventory[i][2]
      end
      i = i + 1
   end
   return 0
end


-- Function seeObject
-- parameters:
-- object: string
-- require: view
-- return the closer case where is object
function	seeObject(object)
   local i = 1
   if ia.view[1] ~= nil then
      ia.caseToGo = 0
      while ia.view[i] do
	 local y = 1
	 while ia.view[i][y] do
	    if ia.view[i][y] == object
	    then
	       ia.caseToGo = i
	       return OK
	    end
	    y = y + 1
	 end
	 i = i + 1
      end
      return KO
   else
      setCommand(op_voir, voir)
      return SAME
   end
end

function	takeObject(object)
   if ia.response.msg ~= nil then
      if ia.response.op == op_prend then
	 if ia.response.msg  == "OK" then -- revoir
	    setResponse(0, nil)
	    return OK
	 else if ia.response.msg  == "KO" then -- revoir
	       setResponse(0, nil)
	       return KO
	    end
	 end
      end
   end
   local msg = prend + " " + object -- \n??
   setCommand(op_prend, msg)
   return SAME
end


function	putDownObject(object)
   if ia.response.msg ~= nil then
      if ia.response.op == op_pose then
	 if ia.response.msg  == "OK" then -- revoir msg resp
	    setResponse(0, nil)
	    return OK
	 else if ia.response.msg  == "KO" then -- revoir
	       setResponse(0, nil)
	       return KO
	    end
	 end
      end
   end
   local msg = pose + " " + object -- \n??
   setCommand(op_pose, msg)
   return SAME
end

----------------------------------------------------------------------------
------------------------------ BROADCAST
----------------------------------------------------------------------------

function broadcastMsg(msg)
   if ia.response.msg ~= nil then
      if ia.response.op == op_broadcast then
	 if ia.response.msg  == "OK" then -- revoir msg resp
	    setResponse(0, nil)
	    return OK
	 end
      end
      setCommand(op_broadcast, msg)
      return SAME
   else
      setCommand(op_broadcast, msg)
      return SAME
   end
end
----------------------------------------------------------------------------

------------------------------ split ---------------------------------------
function split(str, pat)
   local t = {}  -- NOTE: use {n = 0} in Lua-5.0
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
----------------------------------------------------------------------------

----------------------------------------------------------------------------
------------------------------ OLD CODE
----------------------------------------------------------------------------

--//////////////////////////////////////////////////////////// TO MODIFY
-- Fonction searchObject
-- parametres:
-- tabView: tab[][]
-- object: string
function	 searchObject(object, case)
   -- local resp
   -- case = seeObject(tabView, object)
   -- if case ~= 0 then
   ia.way = getWayToCAse(ia.view, case)
   goToCase(way)
   takeObject(object)
   resp = catchResponse(take)
   if resp == ok then
      return true
   end
   --   end
   return false --////////////
   --else
   --if times == nil then
   --times = 3
   --end
   --   if times >= 0 then
   --turnleft()
   -- call_view()
   -- view = catchResponse(voir)
   -- tabView = getViewTab(view)
   --times = times - 1
   --searchObject(tabView, object, times)
   --else
   --   return false
   --end
   --end
end

--////////////////////////////////////////////////////////// TO MODIFY
-- Fonction searchStone
-- parametres:
-- inventory: tab[][]
-- level: int
function	 searchStones(stones)
   sendCommandLua("vision")
   view = catchResponse(voir)
   tabView = getViewTab(view)
   -- TO DO => sort stones by distance => sortTabStones(stones, tabView)
   local i = 1
   while stones[i] do
      if stones[i][2] < stones[i][3] then
	 local case = seeObject(tabView, object)
	 if case ~= 0 then
	    if searchObject(tabView, stones[i][1], case) == true then
	       stones[i][2] = stones[i][2] + 1
	       call_view()
	       view = catchResponse(voir)
	       tabView = getViewTab(view)
	       find = true
	    end
	 end
      end
      i = i + 1
   end
end
----------------------------------------------------------------------------
