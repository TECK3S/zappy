-- Fonction get_qty_object
-- parametres:
-- inventory: tab[][]
-- object: string => objet dt la qte est a envoye
function	getQtyObject(inventory, object)
   local i = 1
   while inventory[i] do
      if inventory[i][1] == object then
	 return inventory[i][2]
      end
      i = i + 1
   end
   return 0
end

-- Fonction searchObject
-- parametres:
-- tabView: tab[][]
-- object: string
function	 searchObject(tabView, object, case)
   -- local resp
   -- case = seeObject(tabView, object)
   -- if case ~= 0 then
   way = getWayToCAse(tabView, case)
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

-- Fonction searchStone
-- parametres:
-- inventory: tab[][]
-- level: int
function	 searchStones(stones)
   call_view()
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