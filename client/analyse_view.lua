-- Fonction getViewTab
-- parse la view sous forme de tableau
-- parametres:
-- view: string
-- return: tab[][]
function	getViewTab(view)
   tabView = {}
   local splitView = split(view, ",")
   local i = 1
   while splitView[i] do
      local s = split(splitView[i], " ")
      tabView[i] = s
      i = i + 1
   end
   return tabView
end


-- Fonction seeObject
-- parametres:
-- view: tab[][]
-- object: string
function	seeObject(tabView, object)
   local i = 1
   while tabView[i] do
      local y = 1
      while tabView[i][y] do
	 if tabView[i][y] == object
	 then
	    return i
	 end
	 y = y + 1
      end
      i = i + 1
   end
   return 0
end