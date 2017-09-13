--lineMrq

--tableau indiquant les objets necessaires pour incatation selon niveau
incatationTable = {{1, 1, 0, 0, 0, 0, 0},
	      {2, 1, 1, 1, 0, 0, 0},
	      {2, 2, 0, 1, 0, 2, 0},
	      {4, 1, 2, 1, 0, 1, 0},
	      {4, 1, 2, 1, 3, 0, 0},
	      {6, 1, 2, 3, 0, 1, 0},
	      {6, 2, 2, 2, 2, 2, 1}
	   }

incatationTableName = {nbPlayer, linemate, deraumere, sibur, mandiane, phiras, thystame}

-- Fonction getInventoryTab
-- parametres:
-- vision: string
-- return: tab[][]
function	getInventoryTab(inventory, level)
   tabInventory = {}
   local splitInventory = split(inventory, ",")
   local i = 1
   while splitInventory[i] do
      local s = split(splitInventory[i], " ")
      tabInventory[i] = s
      i = i + 1
   end

   i = 1
   while tabInventory[i] do
      local y = 2
      while incantationTableName[y] do
	 if tabInventory[i][1] == incantationTableName[y]
	 then
	    tabInventory[i][3] = incantationTable[level][y]
	 end
	 y = y + 1
      end
      i = i + 1
   end
   return tabInventory
end

-- Fonction needFood
-- parametres:
-- vision: tab[][]
-- return: bool
function	needFood (inventory)
   if getQtyObject(invetory, food) < 2 --/////////// a revior
   then
      return true
   else
      return false
   end
end

-- Fonction needStones
-- parametres:
-- vision: tab[][]
-- level: int
-- return: bool
--function needStones(inventory, level)
function needStones(inventory)
   -- local i = 2
   -- while incantationTableName[i] do
   --    local y = 1
   --    local find = false
   --    while inventory[y] do
   --	if inventory[y][1] ~= nourriture then
   -- 	 if inventory[y][1] == incantationTableName[i]
   -- 	 then
   -- 	    if inventory[y][2] < incantationTable[level][i]
   -- 	    then
   -- 	       return true
   -- 	    end
   -- 	 end
   --	end
   -- 	 y = y + 1
   --    end
   --    if find == false
   --    then
   -- 	 return false
   --    end
   --    i = i + 1
   -- end
   need = {}
   local i = 1
   local y = 0
   while inventory[i] do
      if inventory[i][1] ~= nourriture
      then
	 if inventory[i][2] < inventory[i][3]
	 then
	    y = y + 1
	    need[y] = inventory[i]
	 end
      end
      i = i + 1
   end
   return need
end

-- ////////////////////
-- Fonction needmorepeople
-- parametres:
-- level: int
-- return: bool
function needMorePeople(level)
   if (nbPeopleSameLevelOnCase) >= incantationTable[level][1]
   then
      return true
   end
   return false
end

-- Fonction analyse_inventory
-- parametres:
-- inv: string => inventory
-- level: int
-- return: bool
function	analyseInventory (inv, level)
   inventory = getInventoryTab(inv)
   if needFood(inventory) == true
   then
      call_view()
      view = get_view()
      tabView = getViewTab(view)
      searchObject(tabView, nourriture)
   else
      --      if needStones(inventory, level) == true
      stones = needStones(inventory)
      if  stones ~= {}
      then
	 --	 searchStones(inventory, level)
	 searchStones(stones, tabView)
      else
	 if needMorePeople(level) == true
	 then
	    searchPeople(level)
	 end
	 doAction(incantation)
	 catchReponse(incantation)
      end
   end
end